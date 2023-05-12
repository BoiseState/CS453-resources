package person

type IStudent interface {
	IPerson						// embedded interface: superclass
}

type Student struct {
	Person						// embedded struct: superclass
	major string
}

func NewStudent(name string, age int, major string) (s *Student) {
	s=new(Student)
	s.Init(name,age,major)
	return
}

func (s *Student) Init(name string, age int, major string) {
	s.Person.Init(name,age)		// superclass constructor
	s.major=major
}

func (s *Student) String() string {
	return s.Person.String()+" "+s.major // super.String()
}
