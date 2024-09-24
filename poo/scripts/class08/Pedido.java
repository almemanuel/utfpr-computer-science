package class08;

public class Pedido {
	private int id;
	private String data;
	private Status statusPedido;
	
	public Pedido(int id, String data) {
		this.id = id;
		this.data = data;
		this.statusPedido = Status.AGUARDANDO_PAGAMENTO;
	}
	
	public String toString() {
		return 	"id: " + this.id + "\n" +
				"data: " + this.data + "\n" +
				"status: " + this.statusPedido + "\n";
	}
	
	public void setStatusPedido(Status novoStatus) {
		this.statusPedido = novoStatus;
	}
}
