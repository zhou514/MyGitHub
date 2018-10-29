// (7) 调用abort函数，异常终止进程
// #include <stdlib.h>
// void abort(void);
// abort通常伴随core文件产生，如果直接exit，不会产生core文件

//异常终止
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
                printf("我要异常终止进程\n");
                abort();
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