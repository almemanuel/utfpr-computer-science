package class09;

public class Teste {
	public static void main(String[] args) {
		Pessoa pessoa = new Pessoa(	"jorginho",
									"01-01-01",
									"M",
									"jorginho@jorginho.net",
									EstadoCivil.SOLTEIRO);
		pessoa.setEndereco("Rua s Pedro", 1000, "Centro", "Itarare", "SP");
		
		System.out.println(pessoa);
	}
}
