// //进程终止
// 1.进程的终止方式
// (1)主函数结束，进程终止
//     结束主函数的方法是代码运行完毕，或调用return
// (2)调用exit函数，进程终止
//     void exit(int status); //退出进程
//     参数 进程结束后要返回给父进程的值

//退出进程
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
                printf("我要退出进程\n");
                exit(0);
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