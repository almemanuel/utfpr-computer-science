package lista04;

public class Endereco {
	private String logradouro, bairro, cidade, unidadeFederativa;
	private int numero;
	
	public Endereco(String logradouro,
					int numero,
					String bairro,
					String cidade,
					String unidadeFederativa) {
		this.logradouro = logradouro;
		this.numero = numero;
		this.bairro = bairro;
		this.cidade = cidade;
		this.unidadeFederativa = unidadeFederativa;
	}
	
	
	private String getLogradouro() {
		return this.logradouro;
	}
	
	
	private int getNumero() {
		return this.numero;
	}
	
	
	private String getBairro() {
		return this.bairro;
	}
	
	
	private String getCidade() {
		return this.cidade;
	}
	
	
	private String getUnidadeFederativa() {
		return this.unidadeFederativa;
	}
	
	private String getAll() {
		return 	this.getLogradouro() + ", " + this.getNumero() + " - " + this.getBairro() + "\n" +
				this.getCidade() + "/" + this.getUnidadeFederativa();
	}
	
	public String toString() {
		return this.getAll();
	}
}
