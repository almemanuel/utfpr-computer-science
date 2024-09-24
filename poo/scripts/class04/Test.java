package class04;

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
		
		System.out.println(car1);
		car1.turnOn();
		System.out.println(car1);
		car1.toAcelerate();
		System.out.println(car1);
		car1.toAcelerate();
		System.out.println(car1);
		car1.toAcelerate();
		System.out.println(car1);
		car1.toAcelerate();
		System.out.println(car1);
		car1.toBreak();
		System.out.println(car1);
		
		System.out.println(car2);
		car2.turnOff();
		car2.toAcelerate();
		car2.toBreak();
		System.out.println(car2);
	}
}