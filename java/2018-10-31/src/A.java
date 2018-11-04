/**
 * 
 * @author Administrator
 *	1.外嵌类中的成员变量可以在内部类中使用；
 *		内部类中的方法也可以调用外嵌类中的方法；
 *	2.外嵌类的类体中可以用内部类声明对象，作为外嵌类的成员。
 *	3.内部类只能供它的外嵌类使用，不能被其他类使用
 *	4.内部类可以被修饰为static内部类；
 *		如果内部类是静态的，那么这个类就不能够调用外嵌类中的成员变量和方法
 */
public class A {  // A -> 外嵌类
	//成员变量 
	int number;
	B number2;
	//方法
	void funA() {}
	
	//类  B -> 内部类
	class B{  //static class B(){}
		B innerObject = new B();
		B(){}
		void funB() {
			funA();
			System.out.println(number);
		}
	}
}
