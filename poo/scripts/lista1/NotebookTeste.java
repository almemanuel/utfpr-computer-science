package lista1;

public class NotebookTeste {
	public static void main(String[] args) {
		Notebook notebook1 = new Notebook();
		notebook1.marca = "Apple";
		notebook1.modelo = "Macbook";
		notebook1.polegadasTela = 14.5;
		notebook1.modeloProcessador = "M1";
		notebook1.quantidadeRam = 8;
		notebook1.capacidadeArmazenamento = 256;
		
		System.out.println(notebook1.marca);
		System.out.println(notebook1.modelo);
		System.out.println(notebook1.polegadasTela);
		System.out.println(notebook1.modeloProcessador);
		System.out.println(notebook1.quantidadeRam);
		System.out.println(notebook1.capacidadeArmazenamento);
	}
}
