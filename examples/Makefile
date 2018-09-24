
all: 
	cd introduction; make 
	cd files-processes; make
	cd device-management; make 
	cd process-management; make 
	cd scheduling; make 
	cd synchronization-part1; make 
	cd synchronization-part2; make 
	cd signals-pipes; make
	cd memory-management; make 
	cd virtual-memory; make 
	cd file-management; make 
	cd security; make 
	cd networking; make 
	cd plugins/; make


zipfile:
	cd introduction; make clean
	cd files-processes/; make clean
	cd device-management; make clean
	cd process-management/; make clean
	cd scheduling; make clean
	cd synchronization-part1; make clean
	cd synchronization-part2; make clean
	cd signals-pipes; make clean
	cd memory-management; make clean
	cd virtual-memory; make clean
	cd file-management; make clean
	cd security; make clean
	cd networking; make clean
	cd plugins; make clean
	zip -x "*/.svn*" -x "*/.project" -x "*/.classpath" -r lab.zip introduction/ files-processes/ device-management/ process-management// scheduling/ synchronization-part1/ synchronization-part2/ signals-pipes/ memory-management/ virtual-memory/ file-management/ security/ networking/ linux_device_drivers/
	zip -x "*/.svn*" -r mswin.zip ms-windows/
	mv mswin.zip lab.zip ../www/lab/

	
clean:
	cd introduction; make clean
	cd files-processes/; make clean
	cd device-management; make clean
	cd process-management; make clean
	cd scheduling; make clean
	cd synchronization-part1; make clean
	cd synchronization-part2; make clean
	cd signals-pipes; make clean
	cd memory-management; make clean
	cd virtual-memory; make clean
	cd file-management; make clean
	cd security; make clean
	cd networking; make clean
	cd plugins; make clean
