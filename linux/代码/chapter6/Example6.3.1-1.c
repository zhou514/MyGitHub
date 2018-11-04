#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc,char **argv){
    pid_t pid;
    int i,fd;
    char *buf="这是守护进程";
    pid=fork();
    if (pid ==-1) exit(1);    //创建进程失败
    else if (pid >0) exit(1); //父进程被关闭
    //----子进程要处理的代码
    printf("进入子进程\n");
    //在子进程创建新的会话
    setsid();
    //设置工作目录为根
    chdir("/");
    //设置权限掩码
    umask(0);
    //返回子进程文件描述符表的项数，并关闭描述符
    for(i=0;i<getdtablesize();i++) close(i);
    //死循环进行守护
    while(1){
         printf("永远写下去\n");
         //以追加方式打开一个日志文件，将适应的信息写入文件
         fd=open("/tmp/daemon.log",O_CREAT |O_WRONLY | O_APPEND,0600);
         if (fd==-1){
             printf("open file error\n");
             exit(1); //结束子进程
         }
         write(fd,buf,strlen(buf)+1);
         close(fd);
         sleep(3);
    }
    return 0;
}
