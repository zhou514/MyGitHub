#include <stdlib.h>
#include <stdio.h>
void close_handler(){
   printf("我是进程关闭时自动调用的函数，相当于析构\n");
}

int main(int argc,char **argv){
    atexit(close_handler);

    return 0;
}
