package class10;

public class Aluno extends Pessoa {
	private String curso;
	
	public Aluno(String nome, int idade, String curso) {
		super(nome, idade);
		this.curso = curso;
	}
	
	public void realizarMatricula() {
		System.out.println(this.nome + " está matriculado no curso " + "this.curso");
	}
}
