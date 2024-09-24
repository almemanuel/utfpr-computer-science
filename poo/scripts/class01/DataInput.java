package class2;

import java.util.Scanner;

public class DataInput {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		System.out.print("Name: ");
		String name = input.nextLine();
		
		System.out.print("Age: ");
		int age = input.nextInt();
		
		System.out.print("weight (Kg): ");
		double weight = input.nextDouble();
		
		System.out.printf("%s\n%d yo\n%.2f Kg\n", name, age, weight);
		
		input.close();
	}
}
