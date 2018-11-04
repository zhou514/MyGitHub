#include <stdio.h> 
#include <string.h> 
int main(int argc,char **argv){      
int s;
    scanf("%d",&s);    
    if (s>100 || s<0)
       printf("输入错误\n");
    else if (s>=90)
       printf("优\n");    
    else if (s>=80)
       printf("良\n");    
    else if (s>=70)
       printf("中\n");    
    else if (s>=60)
       printf("差\n");    
    else 
       printf("不及格\n");
    
}
