/**
 * 
 * @author Administrator
 * function:在构造方法里面使用this
 */
public class People {
	
	int leg;
	int hand;
	String name;
	
	//构造方法
	People(){
		this.init1();
	}
	//方法重载：方法名相同，但是参数个数不同或参数的类型不同
	People(String name){
		this.name = name;
		this.init2();
	}
	People(int age){
		
	}
	
	void init1(){
		leg = 2;
		hand = 2;
		System.out.println("有" + hand + "只手," + leg + "条腿.");
	}
	void init2(){
		leg = 2;
		hand = 2;
		System.out.println(name + "有" + hand + "只手," + leg + "条腿.");
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		People tom = new People();// 声明一个People对象 tom
		People boshi = new People("布什");
	}

}
