package class04;

public class Human {
	String name;
	int age;
	double weight;
	boolean isWalk = false;
	boolean isRun = false;
	boolean isTalk = false;
	
	public void toWalk() {
		if(!isWalk) {
			isWalk = true;
		}
	}
	
	
	public void toRun() {
		if(!isRun) {
			isRun = true;
		}
	}
	
	
	public void toTalk() {
		if(!isTalk) {
			isTalk = true;
		}
	}
	
	public String toString() {
		return	"---" + "\n" +
				"Name: " + name + "\n" +
				"Age: " + age + "\n" + 
				"Weight: " + weight + " Kg\n" +
				"Is walk? " + isWalk + "\n" +
				"Is run? " + isRun + "\n" +
				"Is talk? " + isTalk + "\n" +
				"---";
	}
}
