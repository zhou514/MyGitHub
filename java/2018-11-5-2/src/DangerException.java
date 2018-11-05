//try {}
//	catch(Exception e) {}
//	finally {//无论try部分是否发生异常，finally语句都会被执行
//		}
//	}
//	特殊情况：
//	1.如果try-catch部分有return语句，那么finally仍然会被执行
//	2.如果try-catch部分执行了程序退出代码，即执行 System.exit(0); ,则不会执行finally子语句；当然也不会执行后面所有语句

public class DangerException extends Exception{
	final String message = "超重";
	public String warnMess() {
		return message;
	}
}
