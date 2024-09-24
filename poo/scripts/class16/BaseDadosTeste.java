package class16;

public class BaseDadosTeste {
	public static void main(String [] args) {
		BaseDados bd = new BaseDados();
		
		String[] elementos = bd.getNomes();
		for(int i = 0, tamanho = elementos.length; i < tamanho; i++) {
			System.out.println(elementos[i]);
		}
		
		bd.inserirNovoNome("AAAA");
		bd.inserirNovoNome("BBBB");
		elementos = bd.getNomes();
		for(int i = 0, tamanho = elementos.length; i < tamanho; i++) {
			System.out.println(elementos[i]);
		}
		
		bd.removerNome("BBBB");
		elementos = bd.getNomes();
		for(int i = 0, tamanho = elementos.length; i < tamanho; i++) {
			System.out.println(elementos[i]);
		}
	}
}
