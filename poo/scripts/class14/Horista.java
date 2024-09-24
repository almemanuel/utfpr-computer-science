package class14;

public class Horista extends Funcionario {
	private double precoHora;
	private int horasTrabalhadas;
	
	
	public Horista(String nome, long cpf, double salarioBase, double precoHora, int horasTrabalhadas) {
		super(nome, cpf, salarioBase);
		this.precoHora = precoHora;
		this.horasTrabalhadas = horasTrabalhadas;
	}
	
	
	@Override
	public double calcularSalario() {
		return super.salarioBase + (this.precoHora * this.horasTrabalhadas);
	}
}
