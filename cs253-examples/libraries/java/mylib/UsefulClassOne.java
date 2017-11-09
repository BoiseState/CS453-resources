package mylib;

public class UsefulClassOne 
{
	public void usefulMethod()
	{
		String methodName = "usefulMethod";
		System.out.println(this.getClass().getSimpleName() + " - " + methodName);
	}
}
