package class16;

public class GerenciadorSorteio {
	private int [] numeros;
	
	public GerenciadorSorteio() {
		// vetor int inicializa automaticamente todos os endereços em 0
		this.numeros = new int[5];
		
		this.numeros[0] = 5;
		this.numeros[1] = 10;
		this.numeros[2] = 15;
		this.numeros[3] = 20;
		this.numeros[4] = 25;
	}

	public int[] getNumeros() {
		return numeros;
	}

	public void setNumeros(int[] numeros) {
		this.numeros = numeros;
	}
}
