package class17;
import java.util.Random;

public class Copo {
	private int id;
	private String cor;
	private String material;
	private int capacidadeMaxima;
	private int capacidadeAtual;
	
	public Copo(int id) {
		this.id = id;
		this.cor = "transparente";
		this.material = "plastico";
		this.capacidadeMaxima = 300;
		this.capacidadeAtual = this.generate();
	}

	public int generate() {
		return new Random().nextInt(this.capacidadeMaxima + 1);
	}
	
	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public String getCor() {
		return cor;
	}

	public void setCor(String cor) {
		this.cor = cor;
	}

	public String getMaterial() {
		return material;
	}

	public void setMaterial(String material) {
		this.material = material;
	}

	public int getCapacidadeMaxima() {
		return capacidadeMaxima;
	}

	public void setCapacidadeMaxima(int capacidadeMaxima) {
		this.capacidadeMaxima = capacidadeMaxima;
	}

	public int getCapacidadeAtual() {
		return capacidadeAtual;
	}

	public void setCapacidadeAtual(int capacidadeAtual) {
		this.capacidadeAtual = capacidadeAtual;
	}

	@Override
	public String toString() {
		return "Copo [id=" + this.getId() + ", cor=" + this.getCor() + ", material=" + this.getMaterial() + ", capacidadeMaxima=" + this.getCapacidadeMaxima()
				+ ", capacidadeAtual=" + this.getCapacidadeAtual() + "]";
	}
}
