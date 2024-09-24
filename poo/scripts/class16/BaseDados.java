package class16;

public class BaseDados {
	private String [] nomes;
	
	public BaseDados() {
		this.nomes = new String[4];
	}
	
	public void inserirNovoNome(String novoNome) {
		for(int i = 0, tamanho = this.nomes.length; i < tamanho; i++) {
			if(this.nomes[i] == null) {
				this.nomes[i] = novoNome;
				break;
			}
		}
	}
	
	public void removerNome(String nome) {
		for(int i = 0, tamanho = this.nomes.length; i < tamanho; i++) {
			if(this.nomes[i].equals(nome)) {
				this.nomes[i] = null;
				break;
			}
		}
	}

	public String[] getNomes() {
		return nomes;
	}

	public void setNomes(String[] nomes) {
		this.nomes = nomes;
	}
}
