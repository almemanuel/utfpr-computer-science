package lista1;

public class CalculadoraTeste {
	public static void main(String[] args) {
		Calculadora calculadora = new Calculadora();
		calculadora.marca = "Casio";
		calculadora.modelo = "XYZ";
		calculadora.tipo = "Cientifica";
		calculadora.memoria = 8;
		
		System.out.println(calculadora.marca);
		System.out.println(calculadora.modelo);
		System.out.println(calculadora.tipo);
		System.out.println(calculadora.memoria);
	}
}
