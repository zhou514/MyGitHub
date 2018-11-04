#include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    int main(int argc,char **argv){
        int i=0;
        pid_t pid=fork();
        if (pid==-1) return 0;//失败
        else if (pid==0){ //子进程
                printf("son pid =%d\n",getpid());
                while(1){
                        printf("son ----- %d\n",i);
                        sleep(1);
                        i++;
                        if (i==5) {
                           printf("我要退出子进程\n");
                           _exit(0);
                        }
                }
                printf("son -- over\n");
        }
        else if (pid>0){ //父进程
                printf("parent pid =%d\n",getpid());
                int a;
                wait(&a);
                printf("----a=%d\n",a>>8);
        }
    }    
