package main

import . "fmt"
import . "./person"

func main() {
	{
		var pp IPerson=NewPerson("Ann",21)
		var ss IStudent=NewStudent("Bob",22,"cs")
		var ps IPerson=NewStudent("Carla",23,"math")
		Printf("pp.Name() => %s\n",pp.Name())
		Printf("ss.Name() => %s\n",ss.Name())
		Printf("pp.String() => %s\n",pp)
		Printf("ss.String() => %s\n",ss)
		Printf("ps.Name() => %s\n",ps.Name())
		Printf("ps.String() => %s\n",ps)
	}
    {
		var pp *Person=NewPerson("Ann",21)
		var ss *Student=NewStudent("Bob",22,"cs")
		var ps IPerson=NewStudent("Carla",23,"math")
		Printf("pp.Name() => %s\n",pp.Name())
		Printf("ss.Name() => %s\n",ss.Name())
		Printf("pp.String() => %s\n",pp)
		Printf("ss.String() => %s\n",ss)
		Printf("ps.Name() => %s\n",ps.Name())
		Printf("ps.String() => %s\n",ps)
	}
	{
		pp:=NewPerson("Ann",21)
		ss:=NewStudent("Bob",22,"cs")
		ps:=NewStudent("Carla",23,"math")
		Printf("pp.Name() => %s\n",pp.Name())
		Printf("ss.Name() => %s\n",ss.Name())
		Printf("pp.String() => %s\n",pp)
		Printf("ss.String() => %s\n",ss)
		Printf("ps.Name() => %s\n",ps.Name())
		Printf("ps.String() => %s\n",ps)
	}
}
