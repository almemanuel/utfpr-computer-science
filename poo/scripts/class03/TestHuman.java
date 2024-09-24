package class03;

public class TestHuman {
	public static void main(String[] args) {
		Human human1 = new Human();
		Human human2 = new Human();
		Human human3 = new Human();
		
		human1.name = "João";
		human1.age = 25;
		human1.weight = 68.5;

        human2.name = "Maria";
		human2.age = 30;
		human2.weight = 55.6;

        human3.name = "José";
		human3.age = 32;
		human3.weight = 62.4;
		
		System.out.printf("%s, %d, %s.2f Kg\n", human1.name, human1.age, human1.weight);
		System.out.printf("%s, %d, %s.2f Kg\n", human2.name, human2.age, human2.weight);
		System.out.printf("%s, %d, %s.2f Kg\n", human3.name, human3.age, human3.weight);
	}
}
