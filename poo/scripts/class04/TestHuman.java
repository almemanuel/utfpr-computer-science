package class04;

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
		
		System.out.println(human1);
		System.out.println(human2);
		System.out.println(human3);
		
		human1.toWalk();
		System.out.println(human1);
		human2.toRun();
		System.out.println(human2);
		human3.toTalk();
		System.out.println(human3);
	}
}
