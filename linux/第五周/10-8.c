#数组 相同类型数据的集合，存储 内存空间是连续
数据类型 数组名[元素的个数]  int array[5];
数组赋值的几个问题：
1. int a[12]; a[i]  i 是下标，范围 0~11
2. []  定义数组时[]里面的数据表示数组中元素的个数
        在使用数组元素时 a[2] []里面的数据表示下标
 
int a[5] = {1,2,3,4,5};
printf("%d,%d,%d,%d",a[0],a[1],a[2],a[3],a[4]);

一维数组 二维数组
int a[2][5]; 
int b[3][4][5];

a 数组名 第0个元素的地址
a[i] 
a[i][j] 

int a[5];
//a + 1 为a[1]的地址 
//(a + 1) + 1
int a[5][4];
//a a[0][0]
// a + 1   a[1]  
//(a + 1) + 1 从a开始的第二个数组（行）的地址

一维数组的名称是一维数组的首地址
(a + 1)[1]  第二行的首地址 即a[1][0]地址

int a[2][2] = {1,2,3,4}; 
1 2 
3 4
int a[2][2] = {{1,2},{3,4}};

//字符串
//字符 char a = 'A';
字符串的本质就是字符数组 
数组的长度是5，字符串的长度是4  ；原因：字符串在存储时默认以"/0"结束
char s[5] = {"abcd"}; 
char s[5] = "abcd";
char s[] = "abcd";

#include <string.h>
常见的函数
strcpy(); 复制
strlen(); 求长度
strcmp(); s1 = s2 返回0；s1 > s2 返回正数 反之 返回负数
strcat(dest, str); strdest  连接
ell  hello
strstr(hello, ell);  字符串查找
strchr(str, c); 字符查找 
gets(s);  从终端获取字符串
atof();  将字符串转换成双精度类型
atoi();

函数
定义格式：
返回类型 函数名(形参列表){
    //函数语句
    return 返回值;
}
int add(int a, int b){
    int c;
    c = a + b;
    return c;
}
函数使用前 声明
int add(int a, int b);

例如： 求数组中的最大值和最小值

指针的使用 本质：地址
int a; // a表示内存的名称 &a是地址
*地址表示内存名 int a = 12； &a  *&a = a 
地址 + num 
char c = 'a'; &c 12 ; c + 5 之后的值'f' ，&c + 5 值为17

int a[8] =  {9,2,3,4,5,6,7,8};
a是内存空间的首地址， *a 是int类型的变量 占4个字节 ，存放的是9
a[0] *a ;  a + 1 表示 a[1] , *(a + 1)是内存名
注意： &a[i] == a + i; *(a + i) == a[i];

指针变量
int a = 12;
int* p = &a; // p = &a; *p == *&a == a;
*p 就是变量名 ，值为12；

int*p = (int*)malloc(4);
