// (8)接收到一个信号并终止
// 如Ctrl+c 发送SIGKILL信号给进程，则进程就会强行关闭。raise函数则允许进程向自身发送信号

// 发送SIGKILL信号
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(int argc,char **argv){
    int i = 0;
    pid_t pid = fork();
    if(pid == -1) return 0; //失败
    else if(pid == 0){ //子进程
        printf("son pid = %d\n",getpid());
        while(1){
            printf("son ---- %d\n",i);
            sleep(1);
            i++;
            if(i == 5){
                printf("我要发送信号终止子进程\n");
                raise(SIGKILL);
            }
        }
        printf("son --- over\n");
    }
    else if(pid > 0){ //父进程
        printf("parent pid = %d\n",getpid());
        int a;
        wait(&a);
        printf("---a = %d\n", a >> 8);
    }
}