Alarm Clock Monitor Example
---------------------------

Watch the behavior by running it for 3 threads.
 
  `java TestAlarm 3`
  
To check, redirect output to a file.
  
  `java TestAlarm 3 > log`
  
Then sort it to check the results:
  
  `cat log | sort --key=1,2 --stable | less`
  
