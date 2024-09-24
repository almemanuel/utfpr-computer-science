package class2;

import java.util.Scanner;

public class Conditional1 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		System.out.print("Number 1: ");
		int number1 = input.nextInt();
		
		System.out.print("Number 2: ");
		int number2 = input.nextInt();
		
		System.out.print("Number 3: ");
		int number3 = input.nextInt();
		
		int largest = 0;
		
		if(number1 > number2 && number1 > number3) {
			largest = number1;
		} else if(number2 > number1 && number2 > number3) {
			largest = number2;
		} else {
			largest = number3;
		}
		
		System.out.printf("\n### %d ###\n", largest);
		
		input.close();
	}
}
