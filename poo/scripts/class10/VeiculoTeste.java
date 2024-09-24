package class10;

public class VeiculoTeste {
	public static void main(String[] args) {
		Carro carro1 = new Carro("Gol", "Volkswagen", 2020, 5, "Etanol", 4);
		carro1.calibrarPneus();
		carro1.abastecer();

		Aviao aviao1 = new Aviao("A-380", "Airbus", 2005, 800, "de Aviação", 70000);
		aviao1.voar();
		aviao1.abastecer();
	}
}
