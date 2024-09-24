package class10;

public class Veiculo {
	protected String modelo, fabricante, combustivel;
	protected int ano, numeroPassageiros;
	
	
	public Veiculo(	String modelo,
					String fabricante,
					int ano,
					int numeroPassageiros,
					String combustivel) 
	{
		this.modelo = modelo;
		this.fabricante = fabricante;
		this.ano = ano;
		this.numeroPassageiros = numeroPassageiros;
		this.combustivel = combustivel;
	}
	
	public void abastecer() {
		System.out.println(this.fabricante + " " + this.modelo + " está abastecendo com combutível " + this.combustivel);
	}
}
