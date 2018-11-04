#include <stdio.h> 
int main(int argc,char **argv){
      int y;
      scanf("%d",&y);
      printf("%s\n",(y%4==0 && y%100!=0 || y%4==0)?"闰年":"平年");
      }
