package class08;

public class TesteCliente {
	public static void main(String[] args) {
		Cliente cliente1 = new Cliente(123, "Jorginho", "01/01/2001", EstadoCivil.SOLTEIRO);
		
		System.out.println(cliente1);
	}
}
