package class02;

import java.util.Scanner;

public class Challenge {
	public static void main(String[] args) {
	 Scanner input = new Scanner(System.in);
	 
	 System.out.print("Full name: ");
	 String fullName = input.nextLine();

	 System.out.print("Gender (F/M): ");
	 String gender = input.nextLine();
	 
	 System.out.print("Civil status: ");
	 String civilStatus = input.nextLine();
	 
	 System.out.print("How many children do you have? ");
	 int children = input.nextInt();
	 input.nextLine();
	 
	 System.out.print("School Level: ");
	 String schoolLevel = input.nextLine();
	 
	 System.out.print("Rent: ");
	 double rent = input.nextDouble();
	 
	 System.out.printf("%s\n%s\n%s\n%d\n%s\n$ %.2f\n", fullName, gender, civilStatus, children, schoolLevel, rent);
	 
	 input.close();
	}
}
