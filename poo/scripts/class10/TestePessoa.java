package class10;

public class TestePessoa {
	public static void main(String[] args) {
		Aluno aluno = new Aluno("j�o", 20, "Ci�ncia da Computa��o");
		aluno.realizarMatricula();
		
		Professor professor = new Professor("jorginho", 35, 1200.0);
		professor.calcularSalario();
	}
}
