public class Bar{
	private String state;

	public Bar(String state){
		this.state = state;
	}

	@Override
	public String toString(){
		return "Bar " + state;
	}
}
