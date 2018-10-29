/**
 * 
 * @author Administrator
 *  子类与继承
 *  继承：一种由已有的类创建新类的机制
 *  由继承所得到的类称为子类，被继承的类称为父类（超类）
 *  java中不支持多重继承，即子类只能有一个父类
 *  使用关键字 extends 继承
 *  
 *  类的树形结构
 *  C是B的子类，B又是A的子类，C称为A的子孙类；根节点是Object类，属于java.lang 包，即Object类是所有类的祖先类
 *  如果一个类在定义时没有使用关键字extends，那么默认他是Object类的子类
 *  
 *  
 *  子类中可以有自己定义的属性和方法，也有一部分从父类继承来
 *  子类和父类是否是属于同一个包，private的属性和方法是不能被子类继承的
 */
//class 子类名 extends 父类名{
//	
//}
//class Students extends People{}
//public class Demo1 extends Object{} 与下面的类定义 相同

public class Demo1 {
	//定义成员变量
	int number1;
	int number2;
	private int number3;
}
