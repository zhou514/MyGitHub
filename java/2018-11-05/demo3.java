////断言 assert
//assert booleanExpression；
//如果booleanExpression返回值为true，程序就从断言处继续执行；
//如果时false时，程序就从断言处停止执行
//assert booleanExpression:messageException;
//例如:
//	assert number >= 0; 若表达式成立，则返回true，否则程序就继续执行
public class demo3 {
	public static void main(String args[]) {
		int []score = {-120,100,98,120,99};
		int sum = 0;
		for(int number:score) {
//			assert number >= 0; "负数不能成绩"
			sum = sum + number;
		}
		System.out.println("成绩是:" + sum);
	}
}	

