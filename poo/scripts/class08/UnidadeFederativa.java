package class08;

public enum UnidadeFederativa {
	ES("Espírito Santo", "ES", "Vitória"),
	MG("Minas Gerais", "MG", "Belo Horizonte"),
	PR("Paraná", "PR", "Curitiba"),
	RS("Rio Grande do Sul", "RS", "Porto Alegre"),
	RJ("Rio de Janeiro", "RJ", "Rio de Janeiro"),
	SC("Santa Catarina", "SC", "Florianópolis"),
	SP("São Paulo", "SP", "São Paulo");
	
	private String nome, sigla, capital;
	
	private UnidadeFederativa(String nome, String sigla, String capital) {
		this.nome = nome;
		this.sigla = sigla;
		this.capital = capital;
	}
	
	public String getNome() {
		return this.nome;
	}
	
	public String getSigla() {
		return this.sigla;
	}
	
	public String getCapital() {
		return this.capital;
	}
}
