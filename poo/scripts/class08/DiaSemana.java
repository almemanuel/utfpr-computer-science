package class08;

public enum DiaSemana {
	DOMINGO(1, "domingo"),
	SEGUNDA(2, "segunda-feira"),
	TERCA(3, "terça-feira"),
	QUARTA(4, "quarta-feira"),
	QUINTA(5, "quinta-feira"),
	SEXTA(6, "sexta-feira"),
	SABADO(7, "sábado");
	
	private int numero;
	private String dia;
	
	private DiaSemana(int numero, String dia) {
		this.numero = numero;
		this.dia = dia;
	}
	
	public int getNumero() {
		return this.numero;
	}
	
	public String getDia() {
		return this.dia;
	}
}
