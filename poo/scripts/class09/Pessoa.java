package class09;

public class Pessoa {
	private String nome, dataNascimento, sexo, email;
	private EstadoCivil estadoCivil;
	private Endereco endereco;
	
	public Pessoa(	String nome,
					String dataNascimento,
					String sexo,
					String email,
					EstadoCivil estadoCivil) {
		this.nome = nome;
		this.dataNascimento = dataNascimento;
		this.sexo = sexo;
		this.email = email;
		this.estadoCivil = estadoCivil;
		this.endereco = new Endereco();
	}
	
	

	public void setEstadoCivil(EstadoCivil estadoCivil) {
		this.estadoCivil = estadoCivil;
	}
	
	
	public void setEndereco(String logradouro,
							int numero,
							String bairro,
							String cidade,
							String unidadeFederativa) {
		this.endereco.setEndereco(logradouro, numero, bairro, cidade, unidadeFederativa);
	}
	
	
	public String toString() {
		return 	"nome: " + this.nome + "\n" +
				"data de nascimento: " + this.dataNascimento + "\n" +
				"sexo: " + this.sexo + "\n" +
				"email: " + this.email + "\n" +
				"estado civil: " + this.estadoCivil.getStatus() + "\n" +
				"endereco: " + this.endereco + "\n";
				
	}
}
