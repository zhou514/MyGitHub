#include <unistd.h>
#include<stdio.h>
#include <errno.h>
    int main(int argc,char **argv){
        char *argls[]={ //同argv
            "ls",
            "-l",
            NULL
        };
        if (execvp("/bin/ls",argls) <0){
//与前一个的区别是将参数序开加入到了字符串列表内
           printf("err=%s\n",strerror(errno));
        }
        return 0;
    }
