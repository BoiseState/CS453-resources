public class NodeStmt extends Node {

	private NodeAssn assn;

	public NodeStmt(NodeAssn assn) {
		this.assn=assn;
	}

	public int eval(Environment env) throws EvalException {
		return assn.eval(env);
	}

	public String code() { return assn.code(); }

}
