
public class Students {
	static String name = "tom";
	String number;
	int age;
	int sex; //0 男 1 女
	static double height = 1.7;
	
//	Students(){}
	//在实例方法中使用类变量
	void function() {
		double sHeight = height;
		System.out.println("实例变量height的值是" + sHeight);
	}
	//类方法中使用实例变量是不可以的，可以使用类变量
	static void fun() {
		String name2 = name;
		//this关键字不能出现在类方法中
	}
	
	public static void main(String args[]) {
		Students s1 = new Students();
		Students s2 = new Students();
		s1.function();
		
	}
	
	
	//非构造方法   重载
	public String getName() {
		return name;
	}
	public String getName(int age) {
		return name;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	public String getNumber() {
		return number;
	}
	public void setNumber(String number) {
		this.number = number;
	}
	public int getAge() {
		return age;
	}
	public void setAge(int age) {
		this.age = age;
	}
	public int getSex() {
		return sex;
	}
	public void setSex(int sex) {
		this.sex = sex;
	}
}
