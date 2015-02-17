public class Foo{

	private String state;

	public Foo(String state){
		this.state = state;
	}

	@Override
	public String toString(){
		return "Foo " + state;
	}

	@Override
	public boolean equals(Object obj){
		return false;
	}

}
