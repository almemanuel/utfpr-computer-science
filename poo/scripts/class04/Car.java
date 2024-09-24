package class04;

public class Car {
	String model;
	String brand;
	int year;
	String licensePlate;
	String color;
	int velocity = 0;
	
	boolean isOn = false;
	
	
	public void turnOn() {
		if(!isOn) {
			isOn = true;
			System.out.println("ON");
		} else {
			System.out.println("ALREADY IS ON");
		}
	}
	
	
	public void turnOff() {
		if(isOn) {
			isOn = false;
			System.out.println("OFF");
		} else {
			System.out.println("ALREADY IS OF");
		}
	}
	
	
	public void toAcelerate() {
		if(velocity <= 150 && isOn) {
			velocity += 10;
			System.out.println("VRUM");
		} else if(!isOn) {
			System.out.println("The car is off");
		} else {
			System.out.println("WARNING: danger velocity");
		}
	}
	
	
	public void toBreak() {
		if(velocity >= 10 && isOn) {
			velocity -= 10;
			System.out.println("BREAK");
		} else if(!isOn) {
			System.out.println("The car is off");
		} else {
			System.out.println("WARNING: the car engine will stop if you brake it");
		}
	}
	
	public String toString() {
		return 	"---" + "\n" +
				"Model: " + model + "\n" +
				"Brand: " + brand + "\n" +
				"Year: " + year + "\n" +
				"License plate: " + licensePlate + "\n" +
				"Color: " + color + "\n" +
				"Velocity: " + velocity + "\n" +
				"Is on? " + isOn + "\n" +
				"---";
	}
}