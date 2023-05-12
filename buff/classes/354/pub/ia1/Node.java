// This class, and its subclasses,
// collectively model parse-tree nodes.
// Each kind of node can be eval()-uated,
// and/or code()-generated.

public abstract class Node {

	protected int pos=0;

	public int eval(Environment env) throws EvalException {
		throw new EvalException(pos,"cannot eval() node!");
	}

	public String code() { return ""; }

}
