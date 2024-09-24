package class15;

public class TesteCompra {
	public static void main(String[] args) {
		CarrinhoCompra carrinho = new CarrinhoCompra(500.00, 100, new Sedex());
		System.out.println("R$ " + carrinho.realizarCompra());
		System.out.println("R$ " + carrinho.calcularImposto());
	}
}
