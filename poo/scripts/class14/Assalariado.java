package class14;

public class Assalariado extends Funcionario {
	private double adicional;
	
	
	public Assalariado(String nome, long cpf, double salarioBase, double adicional) {
		super(nome, cpf, salarioBase);
		this.adicional = adicional;
	}
	
	
	@Override
	public double calcularSalario() {
		return super.salarioBase + this.adicional;
	}
}
