package class11;

public class ImovelUsado extends Imovel {
	private double valorDesconto;
	
	public ImovelUsado(String endereco, double valorBase, double valorDesconto) {
		super(endereco, valorBase);
		this.valorDesconto = valorDesconto;
	}
	
	public void imprimirDados() {
		super.imprimirDados();
		System.out.println("Valor final: R$ " + (super.valorBase - this.valorDesconto));
	}
}
