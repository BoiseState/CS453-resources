

echo '---testing mycp---'
echo
for i in 1 2 3 4 5 
do
	time mycp 8192 test3.data tt 2>&1 | awk 'NR == 1 {print $1, " ", $2, " ", $3}'
done

echo '---testing multi-threaded copy with busy waiting  ---'
echo
for i in 1 2 3 4 5 
do
	time thread-cp 8192 test3.data tt 2>&1 | awk 'NR == 1 {print $1, " ", $2, " ", $3}'
done

echo '---testing multi-threaded copy with semaphores  ---'
echo
for i in 1 2 3 4 5 
do
	time tsc 8192 test3.data tt 2>&1 | awk 'NR == 1 {print $1, " ", $2, " ", $3}'
done
