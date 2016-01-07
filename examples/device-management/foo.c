/*
 *  linux/drivers/foo.c
 *
 *  Copyright (C) 1997  Fernando Matia
 */

/*
 *	foo.c
 *
 * This module exports the foo io functions:
 * 
 *     'foo_open()'
 *     'foo_write()'
 *     'foo_read()'
 *     'foo_ioctl()'
 *     'foo_release()'
 *
 */

#undef  FOO_DEBUG               /* Do you want to debug the driver?       */
#define FOO_NAME "foo"          /* A name for the driver                  */

#include <linux/foo.h>          /* foo driver definitions and structures  */
#include <linux/sched.h>        /* For request_irq() & free_irq()         */
#include <linux/errno.h>        /* For error numbers                      */
#include <linux/kernel.h>       /* For printk()                           */
#include <linux/time.h>         /* For struct timeval                     */
#include <linux/major.h>        /* For major devices numbers              */
#include <linux/fs.h>           /* For struct file_operations             */
                                /* and register_*dev()                    */
#include <asm/segment.h>        /* For memcpy_*fs()                       */
#include <asm/io.h>             /* For inb*() and outb*                   */
#include <asm/system.h>         /* For assembler nop, cli and sti         */
extern unsigned long int loops_per_sec;  /* Used in delay.h by udealy()   */
#include <asm/delay.h>          /* For udelay() < 1ms                     */
#include <linux/ioport.h>       /* For check_region(), request_region(),  */
                                /* release_region() and get_ioport_list() */
#include <linux/mm.h>           /* verify_area() and VERIFY_READ or WRITE */

static int foo_status = NOT_PRESENT;        /* Status of the device       */
static int foo_x;                           /* Driver internal data       */
static long foo_y;

static char init_8259_M_imr, init_8259_S_imr; /* Interrupt mask registers */


/**************************************************************************/
/* ----  TIMING SPECIFIC FUNCTIONS -------------------------------------- */
/**************************************************************************/

/* shdel is a short delay calculated.                                     */
/* If used in an int routine keep the delay VERY small.                   */
static void vshdel(unsigned int cmsecs)  /* Call with # of 10 usecs delays*/
{
    udelay(cmsecs*10);
}


/**************************************************************************/
/* ----  CARD SPECIFIC FUNCTIONS ---------------------------------------- */
/**************************************************************************/

static void Write_port(int *value)
{
    outb_p(*value, FOO_PORT_1);
}

static void Read_port(long *value)
{
    *value = (float) (inb_p(FOO_PORT_4) << 8);
    vshdel(200);
    *value += (float) inb_p(FOO_PORT_3);
    *value = foo_x * 100;
}


/*************************************************************************/
/* ---- Interrupt FUNCTIONS -------------------------------------------- */
/*************************************************************************/

/* Mask an interrupt */
static void mask_interrupt(unsigned char mask, unsigned short ad8259)
{
    /* This sets the 8259 mask bit high to disable the interrupt */
    outb_p(inb_p(ad8259+1) | mask, ad8259+1);
}

/* Unmask an interrupt                                                   */
/* It takes the mask byte holding a 1 in the appropriate bit for the int */
/* to unmask and the base address of the 8259 chip.                      */
static void unmask_interrupt(unsigned char mask, unsigned short ad8259)
{
    /* This sets the 8259 mask bit low to enable the interrupt */
    outb_p(inb_p(ad8259+1) & (~mask), ad8259+1);
}

static void touch_irq_routine(int irq, void *dev_id, struct pt_regs *regs)
{
    cli();
    /* Do an E-stop or something... */
    sti();
}

/* This installs the touch interrupt at the IRQ specified by TOUCH_INT.  */
static int install_touch(void)
{
    int error;

    cli();  /* Stop interrupts */
    error = request_irq(TOUCH_INT, touch_irq_routine, SA_INTERRUPT,
                        FOO_NAME, NULL);
    switch( error ) {
        case  OK    : break;
        case -EINVAL:
        case -EBUSY :
        default     : return error;
        }
    unmask_interrupt(TOUCH_MASK, TOUCH_8259);            /* Mask off */
    sti();

    return OK;
}

static void remove_touch(void)
{
    cli();                                    /* Turn off interrupts */
    free_irq(TOUCH_INT, NULL);
    mask_interrupt(TOUCH_MASK, TOUCH_8259);               /* Mask on */
    sti();                                      /* Turn ints back on */
}

/**************************************************************************/
/* ----  DRIVER SPECIFIC FUNCTIONS -------------------------------------- */
/**************************************************************************/

static int foo_read(struct inode *inode, struct file *file,
                     char *buf, int count)
{
    int num_bytes;     /* Number of bytes to return */

    Read_port(&foo_y);
    num_bytes = sizeof(long);
    memcpy_tofs(buf, (char *) &foo_y, num_bytes);

    /* Successful return point */
    return num_bytes;
}

static int foo_write(struct inode *inode, struct file *file,
                      const char *buf, int count)
{
    int num_bytes;     /* Number of bytes to read */

    num_bytes = sizeof(int);
    memcpy_fromfs((char *) &foo_x, buf, num_bytes);
    Write_port(&foo_x);

    /* Successful return point */
    return num_bytes;
}

static int foo_ioctl(struct inode *inode, struct file *file,
                      unsigned int cmd, unsigned long arg)
{
    int error;
    int num;
#ifdef FOO_DEBUG
    printk("cmd = 0x%08x\n", cmd);
    printk("arg = %lu\n", arg);
#endif
    switch( cmd ) {
        case FOO_RESET     : foo_y = foo_x = 0;
                             break;
        case FOO_SET       : error = verify_area(VERIFY_READ,
                                    (void *) arg, sizeof(int));
                             if( error ) return error;
                             num = get_fs_byte((int *) arg);
                             foo_y = (long) num * (long) foo_x;
                             break;
        case FOO_GET       : error = verify_area(VERIFY_WRITE,
                                    (void *) arg, sizeof(int));
                             if( error ) return error;
                                    num = foo_x;
                             put_fs_byte(num, (int *) arg);
                             break;
        default            : return -ENOSYS; /* Function not implem. */
        }

    return OK;
}

/* This open funtion hasn't been designed to be openned by two  */
/* processes at the same time. We check this through DEV_IN_USE.*/
static int foo_open(struct inode *inode, struct file *file)
{
    /* Initialization check result */
    switch( foo_status ) {
        case NOT_PRESENT: return -ENXIO;  /* No such device */
        case DEV_IN_USE : return -EBUSY;  /* Device busy    */
        case DEV_READY  : break;          /* Device ready   */
        default         : return -ENXIO;  /* Unknown status */
        }

    /* Gets the initial values of the two 8259 ports */
    init_8259_M_imr = inb_p(MASTER_8259);
    init_8259_S_imr = inb_p(SLAVE_8259);

    /* Install irq handlers */
    if( install_touch() ) {    /* Install touch irq handler */
        return -EPERM;
        }

    /* Successful return point */
    foo_status = DEV_IN_USE;
    return OK;
}

static void foo_release(struct inode *inode, struct file *file)
{
    /* Release irq handlers */
    remove_touch();            /* Release touch interrupt */

    /* Restore the initial values of the two 8259 ports */
    outb_p(init_8259_M_imr, MASTER_8259);
    outb_p(init_8259_S_imr, SLAVE_8259);

    /* Successful return point */
    foo_status = DEV_READY;
    return;
    }

    static struct file_operations foo_fops = { /* Driver available functions */
        NULL,           /* foo_lseek   */
        foo_read,       /* foo_read    */
        foo_write,      /* foo_write   */
        NULL,           /* foo_readdir */
        NULL,           /* foo_select  */
        foo_ioctl,      /* foo_ioctl   */
        NULL,           /* foo_mmap    */
        foo_open,       /* foo_open    */
        foo_release     /* foo_release */
        };

int foo_init(void)
{
#ifdef FOO_DEBUG
    int len;
    char buf[4096];
#endif

    /* Ask for a free major device number */
    if( register_chrdev(FOO_MAJOR, FOO_NAME, &foo_fops)) {
        printk("unable to get major %d for FOO\n", FOO_MAJOR);
        return -EIO;
        }

    /* Test if IO address is free */
    if( check_region(FOO_IO_BASE_ADDRESS, FOO_NUM_PORTS)) {
        printk("FOO error: IO address already in use\n");
        foo_status = NOT_PRESENT;
        unregister_chrdev(FOO_MAJOR, FOO_NAME);
        return -EIO;
        }

    /* Register IO address */
    request_region(FOO_IO_BASE_ADDRESS, FOO_NUM_PORTS, "foo");

#ifdef FOO_DEBUG
    /* Get IO port list */
    len = get_ioport_list(buf);
    buf[len] = '\0';
    printk("FOO port list:\n%s\n", buf);
#endif

    /* Test if hardware is present                               */
    Write a dummy value to a test port and read back to check */
    outb_p(FOO_DUMMYVAL, FOO_TESTPORT);
    vshdel(50);
    if( FOO_DUMMYVAL != inb_p(FOO_TESTPORT) ) {
        printk("FOO error: foo card not detected\n");
        foo_status = NOT_PRESENT;
        release_region(FOO_IO_BASE_ADDRESS, FOO_NUM_PORTS);
        unregister_chrdev(FOO_MAJOR, FOO_NAME);
        return -EIO;
        }

    /* Test irq handlers */
    if( install_touch() ) { /* Test touch handler */
        printk("FOO error: cannot install touch irq handler\n");
        foo_status = NOT_PRESENT;
        release_region(FOO_IO_BASE_ADDRESS, FOO_NUM_PORTS);
        unregister_chrdev(FOO_MAJOR, FOO_NAME);
        return -EIO;
        }
    remove_touch();

    /* Initialize driver internal data */
    foo_x = 0;
    foo_y = 0;

    /* Successful return point */
    printk("FOO: driver initialized with major %d\n", FOO_MAJOR);
    foo_status = DEV_READY;
    return OK;
    }
