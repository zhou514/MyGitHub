#include <stdio.h>
int main(int argc,char **argv){
         int i=0;
         int sum=0;
     LOOP://标签
         sum+=i++;
         if (i<10) goto LOOP; //i只要小于10就跳到前面重复执+
         printf("--- %d\n",sum);
     }
