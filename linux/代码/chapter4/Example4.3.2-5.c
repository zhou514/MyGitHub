#include <stdio.h>
int main(int argc,char **argv){
        int i,sum;
        for(i=0,sum=0;i<10;){  //同while，注意多了两个;号
          sum+=i++;
        }
        printf("--- %d\n",sum);
    } 
