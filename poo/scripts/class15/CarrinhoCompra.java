package class15;

public class CarrinhoCompra {
	private double valorProdutos;
	private int distancia;
	private Frete frete;
	private Imposto imposto;
	
	
	public CarrinhoCompra(double valorProdutos, int distancia, Frete frete) {
		this.valorProdutos = valorProdutos;
		this.distancia = distancia;
		this.frete = frete;
		this.imposto = new IOF();
	}
	
	
	public double getValorCompra() {
		return this.valorProdutos;
	}
	
	
	public Frete getFrete() {
		return this.frete;
	}
	
	
	public int getDistancia() {
		return this.distancia;
	}
	
	
	public Imposto getImposto() {
		return this.imposto;
	}
	
	
	public double realizarCompra() {
		return this.getValorCompra() + this.getFrete().calcularFrete(this.getDistancia());
	}
	
	
	public double calcularImposto() {
		return this.getImposto().calcularImposto(this.getValorCompra());
	}
}
