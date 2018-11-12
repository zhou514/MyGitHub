// 1.字符串与字符数组
//将String对象的字符序列放到数组中
// public void getChars(int start,int end,char c[],int offset);
//把位置start开始到end-1位置结束的字符 放到 数组c中，从数组offset位置开始放；注意：必须要保证数组c能够容纳下要被复制的字符

//把字符串对象的字符序列的全部字符都放在一个字符数组中
// public char[] toCharArray();
// 返回值是一个字符数组
// 数组的长度是String对象字符序列的长度

public class demoString{
    public static void main(String args[]) {
        char []a,c;
        String s = "1945年8月15日是抗战胜利";
        a  = new char[4];
        s.getChars(11, 15, a, 0); //把字符串中相应的内容放到字符数组a中 
        System.out.println(a);
        c = "今天天气不好，心情也不好！".toCharArray();
        for (int i = 0; i < c.length; i++) {
            System.out.println(c[i]);
        }
    }
}

