package class15;

public class Correios implements Frete {

	@Override
	public double calcularFrete(int distancia) {
		return 10.00 + (0.30 * distancia);
	}
}
