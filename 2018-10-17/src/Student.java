
public class Student extends People {
	int number; //子类的属性
	//子类的方法
	void tellNumber() {
		System.out.println("学号是："  + number);
	}
	
	int add(int x, int y) {
		return x + y;
	}
}
