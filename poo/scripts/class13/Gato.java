package class13;

public class Gato extends Mamifero {
	public Gato(String nome) {
		super(nome);
	}
	
	
	@Override
	public void emitirSom() {
		System.out.println(super.nome + " est� miando");
	}
}
