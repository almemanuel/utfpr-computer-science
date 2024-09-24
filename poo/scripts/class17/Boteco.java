package class17;

public class Boteco {
	private int cnpj;
	private String nome;
	private Copo[] engradado;
	
	public Boteco(int cnpj, String nome) {
		this.cnpj = cnpj;
		this.nome = nome;
		this.engradado = new Copo[24];
		this.inicializarCopos();
	}
	
	private void inicializarCopos() {
		for(int i = 0, tamanho = this.engradado.length; i < tamanho; i++) {
			Copo copo = new Copo(i);
			this.engradado[i] = copo;
		}
	}
	
	public void imprimirCopos() {
		System.out.println("CNPJ: " + this.cnpj);
		System.out.println("Nome: " + this.nome);
		for(int i = 0, tamanho = this.engradado.length; i < tamanho; i++) {
			System.out.println(this.engradado[i]);
		}
	}
}
