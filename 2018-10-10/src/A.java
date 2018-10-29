/**
 * 在实例方法中使用this
 * @author Administrator
 *
 */
public class A {
//	只能通过对象来调用，不能用类名调用；
//	当this关键字出现在实例方法中，this就代表正在调用该方法中的对象；
//	实例成员变量在实例方法中出现时：this.成员变量
//	当static成员变量在实例方法中出现时 格式： 类名.成员变量
	int x;//成员变量
	static int y;
	void function1() {
		this.x = 100;
		A.y = 200;
	}
	//同function1
	void function2() {
		x = 100;
		y = 200;
	}
	//当实例成员变量名字和局部变量名字相同时，成员变量前面的"this."或"类."不能省略
	void function3() {
		int x = 300; //局部变量
		int y = 400;
		this.x = x;
		A.y = 200;
	}
	//this.方法  ： 类的实例方法中调用类的其他方法
	
//	void fun1(int a) {int a;}
}
