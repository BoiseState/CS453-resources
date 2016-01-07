/*
 *  /usr/include/linux/foo.h
 *
 *  Copyright (C) 1997  Fernando Matia
 */

/*
 *     foo.h
 *
 * Header file for foo.c
 *
 */

#ifndef _FOO_H
#define _FOO_H

#include <sys/ioctl.h>      /* For _IO macros */

#define OK   0

#define NOT_PRESENT 0
#define DEV_READY   1
#define DEV_IN_USE  2

/* 0x09 has been set arbitrarily by Fernando Matia */
#define FOO_MAGIC   0x09
#define FOO_RESET   _IO(FOO_MAGIC, 0x01)
#define FOO_SET     _IOW(FOO_MAGIC, 0x02, int)
#define FOO_GET     _IOR(FOO_MAGIC, 0x03, int)

/* These are some hardware specific defines for the PC's */
/* 8259 interrupt controller chips                       */
#define MASTER_8259    0x20
#define SLAVE_8259     0xa0
#define TOUCH_INT      0x0c           /* irq 12          */
#define TOUCH_8259     SLAVE_8259     /* int cont addr   */
#define TOUCH_MASK     0x10           /* int bit mask    */

/* This is the FOO card's base address */
#define FOO_IO_BASE_ADDRESS  0x1c0   /* address of first 8255 */

/* These are the ports available on the card */
#define FOO_PORT_1        (FOO_IO_BASE_ADDRESS)
#define FOO_PORT_2        (FOO_IO_BASE_ADDRESS + 1)
#define FOO_PORT_3        (FOO_IO_BASE_ADDRESS + 2)
#define FOO_PORT_4        (FOO_IO_BASE_ADDRESS + 3)

#define FOO_NUM_PORTS     4 
#define FOO_TESTPORT      FOO_PORT_3              /* Port to test hard */
#define FOO_DUMMYVAL      0x8a                    /* Value to write    */

int foo_init(void);

#endif /* _FOO_H */
