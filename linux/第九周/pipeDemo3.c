// 有名管道，用于任何两个进程之间的通信；
// FIFO文件与普通文件区别：
// 1.普通文件无法实现字节流方式管理，而且多进程之间访问共享资源时可能出现问题；
// 2.FIFO文件采用字节流方式处理，遵循先进先出原则，不涉及共享资源
// 操作流程
// mkfifo->open->read(write)->close->unlink

// 1.创建有名管道
// int mkfifo(char *pathname,mode_t mode);
// pathname为管道建立的临时文件，文件名在管道创建之前不能存在；
// mode为管道的访问权限，如0666
// 返回值 成功0，失败-1
// 有名管道创建时只用在写端创建，不用在读端创建

// 2.打开管道
// 使用open函数，默认设置为阻塞模式

// 3.管道读写
// 使用read和write函数
// （1）阻塞模式
// （2）非阻塞模式

// 4.管道关闭
// 用close函数，进程关闭前，只需要关闭各自的描述符

// 5.文件移除
// 用unlink函数，将临时文件及时清除。在写端移除，不需要再读端移除


//任意进程间的通信 服务器端
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    int err = mkfifo("/tmp/myfifo",0666);
    if(err == -1){
        printf("file name is exist\n");
        return 0;
    }
    int fd = open("/tmp/myfifo",O_WRONLY);
    if(fd == -1){
        printf("open error!\n");
        unlink("/tmp/myfifo");
        return 0;
    }
    char buf[256];
    while(1){
        scanf("%s",buf);
        int size = write(fd,buf,strlen(buf));
        printf("write size = %d,buf = %s\n",size,buf);
        if(strcmp(buf,"q") == 0) break;
    }
    close(fd);
    unlink("/tmp/myfifo");
}