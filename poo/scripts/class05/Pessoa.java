package class05;

public class Pessoa {
	private Integer codigo;
	private String nome;
	private String genero;
	private String estadoCivil;
	private Double altura;
	private Double peso;
	private Boolean status;
	
	public Pessoa(Integer codigo, String nome, String genero, String estadoCivil, Double altura, Double peso, Boolean status) {
		this.codigo = codigo;
		this.nome = nome;
		this.genero = genero;
		this.estadoCivil = estadoCivil;
		this.altura = altura;
		this.peso = peso;
		this.status = status;
	}
	
	public String toString() {
		return 	"---" + "\n" +
				"codigo: " + this.codigo + "\n" +
				"nome: " + this.nome + "\n" +
				"genero: " + this.genero + "\n" +
				"estado civil: " + this.estadoCivil + "\n" +
				"altura: " + this.altura + "\n" +
				"peso: " + this.peso + "\n" +
				"status: " + this.status + "\n" +
				"---" + "\n";
	}
}
