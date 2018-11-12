import java.util.Scanner;

public class demo1{
    public static void main(String args[]) {
        String regex = "[a-zA-Z|0-9|_]+";
        Scanner scanner = new Scanner(System.in);
        String str = scanner.nextLine();
        if(str.matches(regex)){
            System.out.println(str + "是由英文字母或数字或下划线组成的！");
        }else{
            System.out.println(str + "中有非法字符，请重新输入！");
        }
    }
}