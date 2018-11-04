#include <malloc.h>
#include <stdio.h>
int* creatmem(int n){
        int i, *tmp=(int *)malloc(4*n);
        for(i=0;i<n;i++)  scanf("%d",tmp+i);
        return tmp;        
    }       
    int main(){
        int i;
        int *a=creatmem(2); //a存的是tmp的值        
        for(i=0;i<2;i++){
           printf("%d\n",a[i]);
        }  
        free(a); //根据地址释放内存  
    }
