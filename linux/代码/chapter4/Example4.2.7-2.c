#include <stdio.h>
int main(int argc,char **argv){
char c; //存字符
c=getchar(); //获取一个字符
char str[256]; //存符串
gets(str); //获取一个字符串，空格也是字符串的一部分
int a; //&a
scanf("%d",&a);
char buf[256];
double b;
scanf("%s %lf",buf,&b);  //默认情况，空格是一个数据的结束
printf("a=%d,buf=%s,b=%lf,c=%c,str=%s\n",a,buf,b,c,str);
    }
