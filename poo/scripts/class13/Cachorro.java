package class13;

public class Cachorro extends Mamifero {
	public Cachorro(String nome) {
		super(nome);
	}
	
	
	@Override
	public void emitirSom() {
		System.out.println(super.nome + " est� latindo");
	}
}
