public class DemoStringBuffer{
    public static void main(String args[]) {
        StringBuffer str = new StringBuffer();
        str.append("大家好");
        System.out.println("str:" + str);
        System.out.println("length:" + str.length());
        System.out.println("capacity:" + str.capacity());
        char ch = str.charAt(1);
        System.out.println("str位置1上的字符是:" + ch);
        str.setCharAt(0, 'h');
        str.setCharAt(1, 'e');
        System.out.println("str:" + str);
        str.insert(2, "llo java");
        System.out.println("str:" + str);
        int index = str.indexOf("好");
        str.replace(index, str.length(), " welcome");
        System.out.println("str:" + str);
    }
}