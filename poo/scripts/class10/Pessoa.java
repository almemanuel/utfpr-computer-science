package class10;

public class Pessoa {
	protected String nome;
	protected int idade;
	protected Endereco endereco;
	
	public Pessoa(String nome, int idade) {
		this.nome = nome;
		this.idade = idade;
		this.endereco = new Endereco("Monteiro Lobato", 123, "Jd Carvalho", "Ponta Grossa", "PR");
	}
}
