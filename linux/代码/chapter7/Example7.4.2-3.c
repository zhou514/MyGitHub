    #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

int main(int argc,char **argv){
    	pid_t pid=fork();
    	if (pid==-1) return 0;
    	else if (pid==0) { //子进程
    		printf("son ----- pid=%d\n",getpid());
    		while(1) sleep(1);
    	}
    	else { //父进程
    		int i;
    		printf("parent ----- pid=%d\n",getpid());
    		sleep(10);
    		kill(pid,SIGKILL); //杀死儿子
    		wait(NULL);
    		printf("kill son over\n");		
    		sleep(3);
    		raise(SIGKILL); //自杀
    		for(i=0;i<10;i++)
    			printf("parent --kill waiting\n");
    			sleep(1);			
    		}		
    	}
