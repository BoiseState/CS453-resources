public class NodeMulop extends Node {

	private String mulop;

	public NodeMulop(int pos, String mulop) {
		this.pos=pos;
		this.mulop=mulop;
	}

	public int op(int o1, int o2) throws EvalException {
		if (mulop.equals("*"))
			return o1*o2;
		if (mulop.equals("/"))
			return o1/o2;
		throw new EvalException(pos,"bogus mulop: "+mulop);
	}

	public String code() { return mulop; }

}
