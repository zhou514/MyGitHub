package com.zhou.java;

public class demo2 {
	void g() {
		demo1 A = new demo1();
		A.weight = 23f; //非法
		A.f(3,4); //非法
		A.number = 23f;  //合法
		A.result = 23f; //合法
	}
}
