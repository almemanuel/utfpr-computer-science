package class13;

public class Losango extends Quadrilatero {
	private Double diagonalMenor;
	private Double diagonalMaior;

	public Losango(Double diagonalMenor, Double diagonalMaior) {
		this.diagonalMenor = diagonalMenor;
		this.diagonalMaior = diagonalMaior;
	}
	
	
	@Override
	public void calcularArea() {
		System.out.println("Area do losango: " + (this.diagonalMenor * this.diagonalMaior) / 2);
	}
}
