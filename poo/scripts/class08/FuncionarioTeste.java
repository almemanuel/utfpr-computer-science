package class08;

public class FuncionarioTeste {
	public static void main(String[] args) {
		Funcionario func = new Funcionario(123, "Jão", "05/05/2005");
		func.setFolga(DiaSemana.DOMINGO);
		System.out.println(func);
	}
}
