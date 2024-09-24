package class10;

public class Professor extends Pessoa {
	private double salario;
	
	public Professor(String nome, int idade, double salario) {
		super(nome, idade);
		this.salario = salario;
	}
	
	public void calcularSalario() {
		System.out.println("O salario do prof " + this.nome + " é R$ " + this.salario);
	}
}
