
public class B {
	//this.方法       类名.方法
	void f() {
		this.g();
		B.h();
	}
	void g() {
		System.out.println("ok");
	}
	static void h() {
		System.out.println("no");
	}
	
	public static void main(String args[]) {
		B b = new B();
		b.f();
	}
}
