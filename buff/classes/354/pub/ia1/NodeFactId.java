public class NodeFactId extends NodeFact {

	private String id;

	public NodeFactId(int pos, String id) {
		this.pos=pos;
		this.id=id;
	}

	public int eval(Environment env) throws EvalException {
		return env.get(pos,id);
	}

	public String code() { return id; }

}
