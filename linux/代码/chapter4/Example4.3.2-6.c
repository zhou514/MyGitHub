#include <stdio.h>
int main(int argc,char **argv){
        int i,sum;
        for(i=0,sum=0;i<10;sum+=i,i++);
        printf("--- %d\n",sum);
    } 
