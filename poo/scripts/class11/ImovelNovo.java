package class11;

public class ImovelNovo extends Imovel {
	private double valorAdicional;
	
	public ImovelNovo(String endereco, double valorBase, double valorAdicional) {
		super(endereco, valorBase);
		this.valorAdicional = valorAdicional;
	}
	
	public void imprimirDados() {
		super.imprimirDados();
		System.out.println("Valor final: R$ " + (super.valorBase + this.valorAdicional));
	}
}
