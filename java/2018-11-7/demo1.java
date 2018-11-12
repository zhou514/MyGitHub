java中常用实用类
1.String类
    import java.lang.String;
    java把String类定义为final类，用户不能扩展String类，String类中不能有子类
    String对象 -> 字符串对象   双引号括起来     
        String str1 = "hello java!";
        String str2 = new String("a new string");
        System.out.println(str1 + str2);
    常用的构造方法
    (1) String(char a[]) 用字符数组创建字符串对象
        char a[] = {'J','a','v','a'};
        String str3 = new String(a); //String str3 = new String("Java");
    (2) String(char a[],int startIndex,int count) 取字符数组中若干个(count)字符组成字符串
        char a[] = {"0",'1','2','3','4','5'};
        String str4 = new String(a,2,4);  //String str4 = new String("1234");

    字符串并置
    String对象可与用 "+" 连接   String str5 = str1 + str2;

    String类中的方法的使用 （已封装好的方法）
        方法一: public int length(); 用来获取String对象的字符序列长度
            String china = "1945年抗战胜利";
            int n1, n2;
            n1 = china.length; //9
            n2 = "你好".length; //2
        方法二: public boolean equals(String s);
            对象.equals(s);    比较对象与s是否相同        注意： 比较相等，在算术运算符中有 "=="  进行判断
            String tom = "张三";
            String cavin = "李四";
            tom.equals(cavin);  // true or false
        方法三: public boolean startsWith(String s); //判断当前对象是否以字符串s为前缀
                public boolean endsWith(String s); //判断当前对象是否以字符串s为后缀
            String str1 = "hellojava!!!";
            String str2 = "你好中国";
            str1.startsWith("he"); //true
            str2.endsWith("天气"); //false
        方法四: public int compareTo(String s); //判断当前对象与s的大小（字母区分大小写），大于s返回正值；如果相同，返回0;如果小于，返回负值
            UNICODE表中
            a -> 97
            A -> 65
            string str3 = "boy";
            str3.compareTo("abcde"); //返回值大于0
            public int compareToIngoreCase(String s); //比较字符串大小，忽略大小写
        方法五: public boolean contains(String s);  //当前对象是否包含s
            String str = "hello";
            str.contains("el");  //true
        方法六: public int indexOf(String s);   //对当前对象进行检索，从位置0开始，判断s是否在对象中，若找到，返回第一次出现s的位置，没有返回-1
                public int lastIndexOf(String s); ////对当前对象进行检索，从位置0开始，判断s是否在对象中，若找到，返回最后一次出现s的位置，没有返回-1
                String对象位置索引从 "0" 开始
                String str = "ABCD"; 索引位置0，1，2，3 -> A B C D
                String str = "I am a good student!";
                str.indexOf("a"); // 2
                str.lastIndexOf("a"); //5
                //indexOf 方法重载
                public int indexOf(String s,int startpoint);
                str.indexOf("good",2); //7
                str.indexOf("a",7); //-1
                //字符串对象在使用目录地址时，对于 "/"  应该用 "\\" 来表示
                //例如    c:/users/music       String str = "c:\\users\\music";
        方法七： public String substring(int startpoint); //获取当前对象中从startpoint位置开始到最后位置上的所有字符 得到新的字符序列
                public String substring(int start，int end); //获取当前对象中从startpoint位置开始到end-1位置上的所有字符 得到新的字符序列
                String str = "我喜欢篮球";
                String newStr = str.substring(1); // 喜欢篮球
                String newStr = str.substring(1,3); //喜欢
        方法八: public String trim(); //对当前对象去掉前后空格得到的新字符序列

    字符串与基本数据类型转换
    import java.lang.Integer     public static int praseInt(String s);
    Byte praseByte();
    short 
    long
    float
    double

    public static String ValueOf(int number);




    