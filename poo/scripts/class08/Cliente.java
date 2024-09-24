package class08;

public class Cliente {
	int codigo;
	String nome, dataNascimento;
	EstadoCivil estadoCivil;
	
	public Cliente(int codigo, String nome, String dataNascimento, EstadoCivil estadoCivil) {
		this.codigo = codigo;
		this.nome = nome;
		this.dataNascimento = dataNascimento;
		this.estadoCivil = estadoCivil;
	}
	
	public String toString() {
		return 	"Codigo: " + this.codigo + "\n" +
				"Nome: " + this.nome + "\n" +
				"Data de Nascimento: " + this.dataNascimento + "\n" +
				"Estado Civil: " + this.estadoCivil + "\n";
	}
}
