package lista04;

public class TestFunc {
	public static void main(String[] args) {
		Funcionario funcionario = new Funcionario(	12345,
													"J�o",
													"01/01/2001",
													"M",
													"Intelig�ncia Artificial",
													"(12) 3456-7890",
													new Endereco(	"Monteiro Lobato",
																	1234,
																	"Jd. Carvalho",
																	"Ponta Grossa",
																	"PR"
																)
													);
		
		System.out.println(funcionario);
	}
}
