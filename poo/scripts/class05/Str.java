package class05;

import java.util.Scanner;

public class Str {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		String any = input.nextLine();
		
		int len = any.length();
		if(len <= 3) {
			System.out.println(any.charAt(3));
		} else {
			System.out.println("String com menos que 3 caracteres");
		}
		System.out.println(len);
		System.out.println(any.toUpperCase());
		
		String [] anySplit = any.split(" ");
		
		String any2 = input.nextLine();
		
		if(any.equals(any2)) {
			System.out.println("Iguais");
		} else {
			System.out.println("Diferentes");
		}
		
		input.close();
	}
}
