
public class ImportantUniversity extends University{
	String department;
	
	void setValue(String d) {
		//重写的目的：子类通过方法的重写可以隐藏继承的方法，子类通过方法的重写可以把父类的状态和行为改变为自身的状态和行为。
		kindsOfClass = 5;
		this.department = d;
		System.out.println("方法重写，重写之后，new对象调用重写的方法");
		System.out.println("子类department is " + d);
		System.out.println(kindsOfClass);
	}
	
	String f() {
		super.department = "IT Department";
		return super.department;
	}
	void f2() {
		System.out.println(super.ClassIsOver());
	}
	
	
}
