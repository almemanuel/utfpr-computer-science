package class17;

public class Aluno {
	private int registroAcademico;
	private String nome;
	private double[] notas;
	
	public Aluno(int totalNotas) {
		this.notas = new double[totalNotas];
	}
	
	public void receberDados() {
		this.registroAcademico = 1234;
		this.nome = "Fulano";
		for(int i = 0, tamanho = this.notas.length; i < tamanho; i++){
			this.notas[i] = 10 - i;
		}
	}
	
	public double calcularMedia() {
		double somaNotas = 0;
		int i;
		
		for(i = 0; i < this.notas.length; i++) {
			somaNotas += this.notas[i];
		}
		
		return somaNotas / i;
	}

	public int getRegistroAcademico() {
		return registroAcademico;
	}

	public void setRegistroAcademico(int registroAcademico) {
		this.registroAcademico = registroAcademico;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public double[] getNotas() {
		return notas;
	}

	public void setNotas(double[] notas) {
		this.notas = notas;
	}
}
