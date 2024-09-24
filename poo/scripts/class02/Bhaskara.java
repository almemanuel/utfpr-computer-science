package class02;

public class Bhaskara {
	public static void main(String[] args) {
		int a = 2;
        int b = 3;
        int c = 4;
        double x = (double)(-b + Math.sqrt(b * b - 4 * a * c)) / 2 * a;
		
		System.out.printf("%f\n", x);
		
	}
}
