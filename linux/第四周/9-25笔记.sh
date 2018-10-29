#输入和输出 <stdio.h> printf() scanf() I/O
#1. int scanf(const char *format,...)
int main(){
    int a;
    scanf("%d",&a);
    printf("--%d\n",a);
}
#gcc example1.c -o example1
#./example1
#12
#--12

#2.int gerchar(void) 获取键盘输入的一个字符
#3.char *gets(char *s) 获取键盘输入的一个字符串

#include<stdio.h>
int main(){
    char c; //存字符
    c = gerchar(); //获取一个字符
    char str[256]; //存字符串
    gets(str); //获取一个字符串，空格也是字符串的一部分
    int a;
    scanf("%d",&a);
    char buf[256];
    double b;
    scanf("%s %lf",buf,&b);
    printf("a=%d,buf=%s,b=%lf,c=%c,str=%s\n",a,buf,b,c,str);
}
#gcc example2.c -o example2
#./example2
#123456789
#55555
#5555
#55555
a=55555,buf=5555,b=55555.000000,c=1,str=23456789

#printf() 输出 同sprintf()

#运算符
#1.算术运算符 + - * / % ++ --
#2.赋值运算符 = += -= *= /= %=
# a = 1;b = 2;a += b;a = a + b
#3.关系运算符 > >= < <= == != 
#4.逻辑运算符 && || !   A || B
int a = 23, b = 12, c = 3, d = 20;
(a += 2) || (b = c + d++);
printf("%d %d %d %d",a,b,c,d);

#从控制台输入一个年份y
(y % 4 == 0 && y % 100 != 0 || y % 4 == 0) ? 闰年 : 平年
#5.条件运算符 a ? b : c
#6.逗号运算符 
int a = 12 , c = 23;
int b = (a++, c+=a++, --a); #b = 13
#7.长度运算符 sizeof() strlen() string.h
sizeof(int); #4
char buf[200]; sizeof(buf);#200
char buf[200] = "abc"; strlen(buf); #3


############################
#控制语句
#1.分支语句
#if
:<<!
    if(condition){
        statement
    }
    else if(condition){
        statement
    }
    else{
        statement
    }
!
#include <stdio.h> 
#include <string.h> 
int main(int argc,char **argv){   
    int y;
    scanf("%d",&y);
    if (y%4==0 && y%100!=0 || y%400==0)
       printf("闰年\n");
    else
       printf("平年\n");
}

#include <stdio.h> 
#include <string.h> 
int main(int argc,char **argv){   
    int w;
    scanf("%d",&w);
    char*  str;
    switch((0+w)%7){
    case 0: str="日"; break;//字符串本身就是地址，地址存在了str变量中
    case 1:  str="一"; break;
    case 2:  str="二"; break;
    case 3:  str="三"; break;
    case 4:  str="四"; break;
    case 5:  str="五"; break;
    case 6:  str="六"; break;
    }
    printf("---今在是周%s\n",str);
}


#include <stdio.h>
int main(int argc,char **argv){
         int i=0;
         int sum=0;
     LOOP://标签
         sum+=i++;
         if (i<10) goto LOOP; //i只要小于10就跳到前面重复执+
         printf("--- %d\n",sum);
     }

#include <stdio.h>
int main(int argc,char **argv){
        int i=0;   //代表要加的数
        int sum=0;//代表最终的和    
        do{
          sum+=i++;
        }while(i<10);
        printf("--- %d\n",sum);
    }


#include <stdio.h>
 int main(int argc,char **argv){
        int i=0;//代表要加的数
        int sum=0;//代表最终的和    
        while(i<10){
          sum+=i++;
        }
        printf("--- %d\n",sum);
    }


#include <stdio.h>
int main(int argc,char **argv){
        int i=0;//代表要加的数
        int sum=0;//代表最终的和    
        for(;i<10;){  //同while，注意多了两个;号
          sum+=i++;
        }
        printf("--- %d\n",sum);
    }    


break continue


任务1：计算半径为1~100的圆的面积，要求面积小于100.
任务2：计算1+2+3+4+...+n
任务3：计算1+1/3+1/5+1/7+...+1/n