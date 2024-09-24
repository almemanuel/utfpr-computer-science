package class08;

public class Empresa {
	private String razaoSocial;
	private int cnpj;
	private UnidadeFederativa uf;
	
	public Empresa(String razaoSocial, int cnpj, UnidadeFederativa uf) {
		this.razaoSocial = razaoSocial;
		this.cnpj = cnpj;
		this.uf = uf;
	}
	
	public String toString() {
		return 	"Raz�o Social: " + this.razaoSocial + "\n" +
				"CNPJ: " + this.cnpj + "\n" +
				"UF da Matriz: " + this.uf.getNome() + "\n";
	}
}
