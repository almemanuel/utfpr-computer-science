package class10;

public class TestePessoa {
	public static void main(String[] args) {
		Aluno aluno = new Aluno("jão", 20, "Ciência da Computação");
		aluno.realizarMatricula();
		
		Professor professor = new Professor("jorginho", 35, 1200.0);
		professor.calcularSalario();
	}
}
