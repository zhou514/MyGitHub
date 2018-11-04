#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

int b=0;
   void f1(int a){
   	b+=20;
   	printf("%d:%d\n",b/60 ,b%60);
   	alarm(20);	
   }
   
   int main(int argc,char **argv){
   	signal(SIGALRM,f1);  //可捕捉信号
   	alarm(20);	//时钟计时器可以唤醒sleep
   	
   	pause();	//任何信号都可以激活暂停  	
   	sleep(10);
   	while(1) {
   		sleep(1);
   		printf("---- \n");
   	}
   }   
