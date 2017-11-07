

This example is by Rob Day and taken from here:

http://www.linux.com/learn/linux-career-center/37985-the-kernel-newbie-corner-kernel-debugging-using-proc-qsequenceq-files-part-1

The global variable jiffies holds the number of ticks that have occurred since the system booted. On boot, the kernel initializes the variable to zero, and it is incremented by one during each timer interrupt. Thus, because there are HZ timer interrupts in a second, there are HZ jiffies in a second. The system uptime is therefore jiffies/HZ seconds.

