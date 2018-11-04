#include <stdio.h>
int main(int argc,char **argv){
          int i,sum;
          i=1,sum=0;
          LOOP:
             if (i>100) goto OVER;
             if (i%3==0 && i%7!=0){
                  sum+=i;
             }
             i++;
             goto LOOP;
          OVER:
          printf("--- %d\n",sum);
      }
