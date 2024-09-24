package class05;

import java.util.Scanner;

public class Mathematic {
    public static void main(String[] args) {
        //System.out.println(Math.sqrt(81));
        //System.out.println(Math.min(1024, 2048));
        //System.out.println(Math.max(1024, 2048));
        //System.out.println(Math.ceil(25.2));
        //System.out.println(Math.floor(25.2));
        //System.out.println(Math.pow(2, 10));
        //System.out.println(Math.round(25.5));
        //System.out.println(Math.PI);

		Scanner input = new Scanner(System.in);

        System.out.print("N1: ");
		int n1 = input.nextInt();
        System.out.print("N2: ");
		int n2 = input.nextInt();

        System.out.println(Math.max(n1, n2));
        System.out.println(Math.sqrt(n1));
        System.out.println(Math.pow(n1, n2));

        input.close();
    }
}