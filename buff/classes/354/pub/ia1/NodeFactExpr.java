public class NodeFactExpr extends NodeFact {

	private NodeExpr expr;

	public NodeFactExpr(NodeExpr expr) {
		this.expr=expr;
	}

	public int eval(Environment env) throws EvalException {
		return expr.eval(env);
	}

	public String code() { return "("+expr.code()+")"; }

}
