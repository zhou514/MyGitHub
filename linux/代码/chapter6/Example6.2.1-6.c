    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    int A;
    int main(int argc,char **argv){
    	  int i=0;    	
        pid_t pid=fork();
        if (pid==-1) return 0;//失败
        else if (pid==0){ //子进程
        	printf("son pid =%d\n",getpid());   
        	A=10; 	
        	while(1){
        		printf("son ----- %d,%d\n",i,A);
        		sleep(1);
        		A++;
        		i++;  
        		if (i==5) return 111;//exit(234);	   
        	}
        	printf("son -- over\n");
        	//
        } 
        else if (pid>0){ //父进程
        	printf("parent pid =%d\n",getpid());   
        	int a;
        	wait(&a);
        	printf("----a=%d\n",a>>8);    	
        }    
    }   
