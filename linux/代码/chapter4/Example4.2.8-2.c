#include <stdio.h> 
#include <string.h> 
int main(int argc,char **argv){
//printf("%d\n",sizeof(int)); //代表用int类型分配的内存是4字节
//int a;
//printf("%d\n",sizeof(a)); //代表a的内存是4字节
//char buf[200];
//printf("%d\n",sizeof(buf)); //200代表buf内存长度为200字节
char buf[200]="abc";
printf("%d\n",strlen(buf)); //buf中字符串的长度为3
}
