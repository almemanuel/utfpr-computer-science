package class08;

public class Funcionario {
	private int registro;
	private String nome, dataAdmissao;
	private DiaSemana folga;
	
	public Funcionario(int registro, String nome, String dataAdmissao) {
		this.registro = registro;
		this.nome = nome;
		this.dataAdmissao = dataAdmissao;
	}
	
	public void setFolga(DiaSemana folga) {
		this.folga = folga;
	}
	
	public String toString() {
		return 	"Registro: " + this.registro + "\n" +
				"Nome: " + this.nome + "\n" +
				"Data de Admissão: " + this.dataAdmissao + "\n" +
				"Dia de folga: " + this.folga.getDia() + "\n";
	}
}
