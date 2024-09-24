package class11;

import java.util.Scanner;

public class ImovelTeste {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		System.out.println("1 - Novo");
		System.out.println("2 - Usado");
		System.out.println("Opcao: ");
		int opcao = input.nextInt();
		Imovel imovel = null;
		switch(opcao) {
			case 1:
				imovel = new ImovelNovo("Vicente de Machado, 1024", 500000.00, 100000.00);
				break;
			case 2:
				imovel = new ImovelUsado("Vicente de Machado, 1024", 500000.00, 100000.00);
				break;
		}
		
		imovel.imprimirDados();
		
		input.close();
	}
}
