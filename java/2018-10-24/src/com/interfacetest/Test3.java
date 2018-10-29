package com.interfacetest;

//如果一个类声明实现一个接口，但是没有重写接口的所有方法,
//那么这个类必须是抽象类，抽象类既可以重写接口中的方法，也可以直接拥有接口中的方法
abstract class Test3 implements Computable{
	public int f(int x) {
		return x;
	}
}
