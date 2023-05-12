{ fpc -ofiles files.p && ./files }

program Files;

type
   Name	       = array [1..20] of char;
   Student     = record
		    name : Name;
		    gpa	 : real;
		 end;	 
   StudentFile = file of Student;

var f: StudentFile;

procedure writeStudent(name: Name; gpa: real);
var s: Student;
begin
   s.name:=name;
   s.gpa:=gpa;
   write(f,s)
end;

procedure writeStudents;
begin
   rewrite(f);
   writeStudent('Ann',3.5);
   writeStudent('Bob',3.0);
   writeStudent('Cam',3.7);
   close(f)
end;

procedure printStudents;
var s: Student;
begin
   reset(f);
   while not(eof(f)) do begin
      read(f,s);
      writeln(s.name,' ', s.gpa)
   end;
   close(f)
end;

begin
   assign(f,'Students.txt');
   writeStudents;
   printStudents
end.
