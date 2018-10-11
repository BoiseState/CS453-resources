
The AlarmClock monitor uses a broadcast signal to wake up every thread at each tick to check if
their alarm is up. Since an arbitrary thread wakes up at each signal, we have to use a broadcast
to make sure threads get a chance.

The better way to solve this would be to use priority-based wait implementation that wraps
around the pthread_cond_wait call.

To verify output, try

TestAlarm 3 4 |  sort --stable -k 2,2


