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
