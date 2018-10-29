// (4)最后一个线程从启动例程返回
// //等待线程返回

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_t pthread_id;

void *run(void *buf){
    int i;
    for(i = 0;i < 10;i++){
        printf("-----%d\n",i);
        sleep(1);
    }
}

void close_handler(){
    pthread_join(pthread_id,NULL);
}

int main(int argc,char **argv){
    atexit(close_handler);
    pthread_create(&pthread_id,NULL,run,NULL);
    pthread_join(pthread_id,NULL);
    return 0;
}

// (5) 最后一个线程调用pthread_exit,方法同（4）
// (6) 最后一个线程对取消请求作出响应 ，同（4）
