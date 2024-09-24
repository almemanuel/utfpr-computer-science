package class12;

import java.util.Scanner;

public class TesteImpressora {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		Impressora printer = null;
		
		System.out.println("Escolha a impressora:");
		System.out.println("1 - Jato de Tinta");
		System.out.println("2 - Laser");
		Integer opcao = input.nextInt();
		
		switch (opcao) {
		case 1:
			printer = new ImpressoraJatoTinta();
			break;
			
		case 2:
			printer = new ImpressoraLaser();
			break;
			
		default:
			System.out.println("Opção inválida.");
		}
		printer.imprimir();
		input.close();
	}
}
