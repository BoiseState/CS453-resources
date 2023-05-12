// This is the main class/method for the interpreter/compiler.
// Each command-line argument is a complete program,
// which is scanned, parsed, and evaluated.
// All evaluations share the same environment,
// so they can share variables.

public class Main {

	public static void main(String[] args) {
		Parser parser=new Parser();
		Environment env=new Environment();
		String code="";
		for (String prog: args)
			try {
				Node node=parser.parse(prog);
				node.eval(env);
				code+=node.code();
			} catch (Exception e) {
				System.err.println(e);
			}
		new Code(code,env);
	}

}
