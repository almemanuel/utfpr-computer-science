package class13;

public class Retangulo extends Quadrilatero {
	private Double base;
	private Double altura;

	public Retangulo(Double base, Double altura) {
		this.base = base;
		this.altura = altura;
	}
	
	
	@Override
	public void calcularArea() {
		System.out.println("Area do retângulo: " + this.base * this.altura);
	}
}
