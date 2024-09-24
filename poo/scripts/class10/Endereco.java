package class10;

public class Endereco {
	private String logradouro, bairro, cidade, unidadeFederativa;
	private int numero;
	
	public Endereco(String logradouro,
					int numero,
					String bairro,
					String cidade,
					String unidadeFederativa)
	{
		this.logradouro = logradouro;
		this.numero = numero;
		this.bairro = bairro;
		this.cidade = cidade;
		this.unidadeFederativa = unidadeFederativa;
	}
}
