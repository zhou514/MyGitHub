
public class Demo3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Student zhangsan = new Student();
		zhangsan.getSex(); //调用父类中的方法，该方法中有父类的私有属性
		zhangsan.age = 18; //访问父类People类中的属性
		zhangsan.number = 10000; //调用自己本身的属性
		zhangsan.showPeopleMessage(); //调用父类People类中的方法
		zhangsan.tellNumber(); //调用自己本身的方法
		int x = 1;
		int y = 2;
		System.out.println("会做加法运算!");
		int result = zhangsan.add(x, y);
		System.out.println("zhangsan会做加法运算，计算结果值为：" + result);
		
		UniverStudent lisi = new UniverStudent();
		lisi.age = 20; //使用爷爷类People类型里面的属性
		lisi.number = 10001; //使用父类Student类里面的属性
		lisi.showPeopleMessage(); //使用爷爷类People类型里面的方法
		lisi.tellNumber(); //使用父类Student类里面的方法
		result = lisi.add(x, y); //使用父类Student类里面的方法
		System.out.println("lisi会做加法运算，计算结果值为：" + result);
		result = lisi.multi(x, y); //使用自身类里面的方法
		System.out.println("lisi会做乘法运算，计算结果值为：" + result);
	}

}