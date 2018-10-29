package com.interfacetest;

public interface Computable { 
	//如果关键字interface前不加public修饰，此时该接口只能被同一个包下面的类实现
	//如果接口用public关键字修饰，那么这个接口可以被所有类实现
	int Max = 46;
	int f(int x);
//	void printTable();
}
