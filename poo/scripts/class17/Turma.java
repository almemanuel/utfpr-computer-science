package class17;

public class Turma {
	Aluno[] alunos;
	
	public Turma() {
		this.alunos = new Aluno[4];
	}
	
	public void entrarDadosAluno() {
		for(int i = 0, tamanho = this.alunos.length; i < tamanho; i++) {
			Aluno aluno = new Aluno(i + 2);
			this.alunos[i] = aluno;
			this.alunos[i].receberDados();
		}
	}
	
	public void exibirDadosTurma() {
		for(int i = 0, tamanho = this.alunos.length; i < tamanho; i++) {
			System.out.println(this.alunos[i].getRegistroAcademico());
			System.out.println(this.alunos[i].getNome());
			
			System.out.println("Notas: ");
			double[] notas = this.alunos[i].getNotas();
			for(int j = 0, totalNotas = notas.length; j < totalNotas; j++) {
				System.out.println(notas[j]);
			}
			
			System.out.println("Média: " + this.alunos[i].calcularMedia());
			System.out.println("---");
		}
	}
}
