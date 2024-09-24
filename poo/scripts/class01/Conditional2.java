package class2;

import java.util.Scanner;

public class Conditional2 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		System.out.print("Value: $ ");
		double value = input.nextDouble();
		
		value = value >= 50 ? value * .9 : value * .95;
		
		System.out.printf("Final value: $%.2f", value);
		
		input.close();
	}
}
