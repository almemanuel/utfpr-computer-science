package class15;

public class IPVA implements Imposto {
	@Override
	public double calcularImposto(double valor) {
		return valor * 0.03;
	}
}
