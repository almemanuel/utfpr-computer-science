package lista04;

public class Funcionario {
	private int numeroRegistro;
	private String nome, dataNascimento, sexo, setor, telefone;
	private Endereco endereco;
	
	public Funcionario(	int numeroRegistro,
						String nome,
						String dataNascimento,
						String sexo,
						String setor,
						String telefone,
						Endereco endereco) {
		this.numeroRegistro = numeroRegistro;
		this.nome = nome;
		this.dataNascimento = dataNascimento;
		this.sexo = sexo;
		this.setor = setor;
		this.telefone = telefone;
		this.endereco = endereco;
	}
	
	public int getNumeroRegistro() {
		return this.numeroRegistro;
	}
	
	
	public String getNome() {
		return this.nome;
	}
	
	
	public String getDataNascimento() {
		return this.dataNascimento;
	}
	
	
	public String getSexo() {
		return this.sexo;
	}
	
	
	public void setSetor(String setor) {
		this.setor = setor;
	}
	
	
	public String getSetor() {
		return this.setor;
	}
	
	
	public void setTelefone(String telefone) {
		this.telefone = telefone;
	}
	
	
	public String getTelefone() {
		return this.telefone;
	}
	
	
	public void setEndereco(Endereco endereco) {
		this.endereco = endereco;
	}
	
	
	public Endereco getEndereco() {
		return this.endereco;
	}
	
	
	public String getAll() {
		return 	"numero do registro: " + this.getNumeroRegistro() + "\n" +
				"nome: " + this.getNome() + "\n" +
				"data de nascimento: " + this.getDataNascimento() + "\n" +
				"sexo: " + this.getSexo() + "\n" +
				"setor: " + this.getSetor() + "\n" +
				"telefone: " + this.getTelefone() + "\n" +
				"endereco: " + this.getEndereco() + "\n";
	}
	
	
	public String toString() {
		return this.getAll();
	}
}
