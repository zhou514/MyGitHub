#include <stdio.h>
int main(int argc,char **argv){
        int i=0;//代表要加的数
        int sum=0;//代表最终的和    
        for(;i<10;){  //同while，注意多了两个;号
          sum+=i++;
        }
        printf("--- %d\n",sum);
    }    
