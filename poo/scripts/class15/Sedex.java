package class15;

public class Sedex implements Frete{
	
	@Override
	public double calcularFrete(int distancia) {
		return 13 + (0.45 * distancia);
	}
}
