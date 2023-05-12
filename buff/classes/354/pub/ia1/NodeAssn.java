public class NodeAssn extends Node {

	private String id;
	private NodeExpr expr;

	public NodeAssn(String id, NodeExpr expr) {
		this.id = id;
		this.expr = expr;
	}

	public int eval(Environment env) throws EvalException {
		return env.put(id, new NodeWr(expr).eval(env));
	}

	public String code() {
		return id + "=" + expr.code() + ";" + new NodeWr(expr).code();
	}

}
