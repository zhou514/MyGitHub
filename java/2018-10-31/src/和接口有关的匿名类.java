/**
 * 
 * @author Administrator
 *	假设Computable是一个接口    interface Computable(){}
 *	创建对象时采用   new Computable() {实现接口的匿名类的类体};
 *	定义方法 void fun(Computable x){}
 *	调用方法fun时        fun(new Computable(){};)
 */
public class 和接口有关的匿名类 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		HelloMachine  machine = new HelloMachine();
		machine.turnOn(new SpeakHello() {  //和接口SpeakHello有关的匿名类
			
			@Override
			public void speak() {
				// TODO Auto-generated method stub
				System.out.println("hello C");
			}
		});
		machine.turnOn(new SpeakHello() {
			
			@Override
			public void speak() {
				// TODO Auto-generated method stub
				System.out.println("hello java");
			}
		});
	}

}
