package class13;

public class TesteQuadrilatero {
	public static void main(String[] args) {
		Quadrado quadrado = new Quadrado(2.0);
		quadrado.calcularArea();

		Retangulo retangulo = new Retangulo(2.0, 5.0);
		retangulo.calcularArea();

		Losango losango = new Losango(2.0, 4.0);
		losango.calcularArea();
	}
}
