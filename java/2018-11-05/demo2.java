
public class demo2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int n = 0;
		int m = 0;
		int t = 1000;
		try {
			m = Integer.parseInt("8888");
			n = Integer.parseInt("ab55");// 发生异常，转向catch
			t = 4444; //因为发生异常，代码转向catch语句，所以t赋值没有被执行
		} catch (NumberFormatException e) {
			// TODO Auto-generated catch block
			System.out.println("异常信息是：" + e.getMessage());
		}
		System.out.println(m + " " + n + " " + t);
		try {
			System.out.println("故意抛出I/O异常!");
			throw new java.io.IOException("我是故意的！"); //转到catch
		} catch (java.io.IOException e) {
			// TODO: handle exception
			System.out.println("异常信息是：" + e.getMessage());
		}
	}

}
