package class09;

public class Endereco {
	private String 	logradouro = "", 
					bairro = "",
					cidade = "",
					unidadeFederativa = "";
	private int numero = 0;
	
	public Endereco() {
		this.logradouro = "";
		this.numero = 0;
		this.bairro = "";
		this.cidade = "";
		this.unidadeFederativa = "";
	}
	
	
	public void setEndereco(String logradouro,
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
	
	
	public String toString() {
		return 	this.logradouro + ", " + this.numero + " - " + this.bairro + "\n" + 
				this.cidade + "/" + this.unidadeFederativa + "\n";
	}
}
