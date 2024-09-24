package class13;

public class Quadrado extends Quadrilatero {
	private Double lado;
	
	
	public Quadrado(Double lado) {
		this.lado = lado;
	}
	
	
	@Override
	public void calcularArea() {
		System.out.println("Area do quadrado: " + Math.pow(this.lado, 2));
	}
}
