package class16;

public class GerenciadorSorteioTeste {
	public static void main(String[] args) {
		GerenciadorSorteio gs = new GerenciadorSorteio();
		System.out.println(gs.getNumeros()); // dessa forma, retorna apenas o endereço
		
		int[] elementos = gs.getNumeros();
		for(int i = 0, tamanho = elementos.length; i < tamanho; i++) {
			System.out.println(elementos[i]);
		}
		
		int [] novoVetor = new int[7];
		for(int i = 0, valor = 100, tamanho = novoVetor.length; i < tamanho; i++, valor--) {
			novoVetor[i] = valor;
		}
		
		gs.setNumeros(novoVetor);
		
		elementos = gs.getNumeros();
		for(int i = 0, tamanho = elementos.length; i < tamanho; i++) {
			System.out.println(elementos[i]);
		}
	}
	
	
}
