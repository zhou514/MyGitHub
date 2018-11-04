#include <stdio.h>
int main(int argc,char **argv){
int a=23;
char str[256];
sprintf(str,"%d",a); //将一个整型转成了字符串
printf("%s\n",str);
sprintf(str,"0x%x，0%o",a,a);//将一个整型转为16和8进制并组合成一个字符串
printf("%s\n",str);               
double b=3.13241324;
sprintf(str,"%.2lf",b);
printf("%s\n",str);       
}
