//调用execvp函数指令
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

int main(int argc,char **argv){
    char *argls[] = { //同argv
        "ls",
        "-l",
        NULL
    };
    if(execvp("/bin/ls",argls) < 0){
        //与pdemo3.c的区别是将参数序列加入到字符串列表内
        printf("err = %s\n",strerror(errno));
    }
    return 0;
}