// // 无名管道
// 操作流程：pipe->read(write)->close
// 1.创建管道
// #include <unistd.h>
// int pipe(int fd[2])
// fd文件描述符数组，由函数填写数据，fd[0]用于管道的read端。fd[1]用于管道write
// 返回值  0成功，-1失败
// 2.管道读写
// 使用read和write函数，读写采用字节流方式
// （1）读管道时，若管道为空，则被堵塞，直到管道另一端write将数据写入管道。若写端关闭了，则返回0
// （2）写管道时。若管道满了，则被堵塞，直到管道另一端read将数据读走
// 3.管道关闭
// 用close函数

//父子进程间的通信
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char  **argv)
{
    /* code */
    int fd[2];
    int err = pipe(fd); //描述符，0表示读，1表示写
    if(err == -1){
        printf("pipe error\n");
        exit(0);
    }
    pid_t pid = fork();
    if(pid == -1) exit(0);
    else if(pid == 0){ //子进程
        close[fd[1]];
        char buf[256];
        int size = read(fd[0],buf,256);
        if(size > 0) printf("son ---- %s\n",buf);
        else printf("son read error\n");
        close[fd[0]];
        exit(0);
    }else if(pid > 0){ //父进程
        close[fd[0]];
        char *str = "1234567890";
        int size = write(fd[1],str,strlen(str));
        sleep(5);
        close[fd[1]];
        wait(NULL);s
        exit(0);
    }
    return 0;
}
