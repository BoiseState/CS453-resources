Producer Consumer using a Shared Queue Monitor
----------------------------------------------


Watch the behavior by running it for 2 producers and 2 consumers.
 
`java PC 10 2 2 1000 2000`

To check, redirect output to a file.
 
 `java PC 10 2 2 1000 2000 > log`
 
Wait for 30 seconds or so. Then sort  output file to check the results:

`cat log | sort --key=1,2 --stable | less`


