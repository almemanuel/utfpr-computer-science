package lista1;

public class AlunoTeste {
	public static void main(String[] args) {
		Aluno aluno = new Aluno();
		
		aluno.ra = 123456;
		aluno.nome = "João";
		aluno.curso = "BCC";
		aluno.turno = "Integral";
		aluno.periodo = 4;
		aluno.coeficiente = 0.85769;
		aluno.situacao = "Regular";
		
		System.out.println(aluno.ra);
		System.out.println(aluno.nome);
		System.out.println(aluno.curso);
		System.out.println(aluno.turno);
		System.out.println(aluno.periodo);
		System.out.println(aluno.coeficiente);
		System.out.println(aluno.situacao);
	}
}
