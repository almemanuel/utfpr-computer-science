package class14;

import java.util.Scanner;

public class TesteFuncionario {
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);

		System.out.printf("1 - Assalariado\n2 - Comissionado\n3 - Horista\nInforme a opção: ");
		int opcao = input.nextInt();

		Funcionario funcionario = null;
		switch(opcao) {
			case 1:
				funcionario = new Assalariado("joão da silva", 1234567, 1000.00, 100.00);
				break;
		
			case 2:
				funcionario = new Comissionado("joão da silva", 1234567, 5000.00, 30000.00, 0.1);
				break;
			
			case 3:
				funcionario = new Horista("joão da silva", 1234567, 1000.00, 50.00, 40);
				break;
		}
		
		System.out.println(funcionario.calcularSalario());

		input.close();
	}
}
