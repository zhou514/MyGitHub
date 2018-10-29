#include <stdio.h>
#include <signal.h>
    #include <stdlib.h>
    #include <unistd.h>

 void f1(int signum){
  	switch(signum){
  	case SIGINT:
  			printf("is SIGINT\n");			
  			break;	
  	case SIGQUIT:
  			printf("is SIGQUIT\n");			
  			exit(0);	
  	case SIGKILL:
  			printf("is SIGKILL\n");		
  	}
  	
 }
  
 int main(int argc,char **argv){
  	signal(SIGINT,f1);  //可捕捉信号  Ctrl-C
  	signal(SIGQUIT,f1); //可捕捉信号  Ctrl-\
  	signal(SIGKILL,f1); //无法捕捉的信号  kill pid  	
  	while(1){
  	 	  sleep(1);	 	  
  	}  	
 } 
