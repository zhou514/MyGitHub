package com.interfacetest;

public class Demo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Test1 t1 = new Test1();
		Test2 t2 = new Test2();
		t1.number = 10 + Computable.Max; //可以直接使用接口名称.常量名
		t2.number = 20 + Computable.Max;
		System.out.println(t1.number + " / " + t2.number);
		System.out.println(t1.f(10));
		System.out.println(t2.f(20));
	}

}
