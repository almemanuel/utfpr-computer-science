package class03;

public class Test {
	public static void main(String[] args) {
		Car car1 = new Car();
		Car car2 = new Car();
		
		car1.model = "Golf";
		car1.brand = "VW";
		car1.year = 2022;
		car1.licensePlate = "ABC-1234";
		car1.color = "red";
		
		car2.model = "Civic";
		car2.brand = "Honda";
		car2.year = 2021;
		car2.licensePlate = "XYZ-6789";
		car2.color = "grey";
		
		System.out.printf("%s %s %s %d %s\n", car1.licensePlate, car1.brand, car1.model, car1.year, car1.color);
		System.out.printf("%s %s %s %d %s\n", car2.licensePlate, car2.brand, car2.model, car2.year, car2.color);
	}
}
