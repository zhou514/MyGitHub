//用execl函数调用指令
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

int main(int argc,char **argv){
    if(execl("/bin/ls","ls","-l",NULL) < 0){
        //注意：第一个参数是包含路径的指令名，第二个参数是指令名，最后一个参数必须为NULL，代表参数序列结束
        printf("err=%s\n",strerror(errno));
    }
    return 0;
}