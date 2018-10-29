#include <stdio.h>
int main(int argc,char **argv){
    //字符串转整型
    int a=atoi(argv[1]); //atoi将字符串argv[1]转换为整型，赋给a
    printf("%d\n",a);
    int b=atoi("8");
    printf("%d\n",b);
    //字符转整型
    int c='8'-'0';
    printf("%d\n",c);
    }
