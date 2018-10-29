#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <pthread.h>
    
    void * run(void *buf){
        int i=0;
        while(1){
           printf("------id=%u,i=%d\n",pthread_self(),i++);
           usleep(1000000);
        }
    }
    
    int main(int argc,char **argv){
        pthread_t pid;
        pthread_attr_t attr;
        struct sched_param param;
        //----设置线程属性----
        pthread_attr_init(&attr); //初始化线程属性
        param.sched_priority=50;
        pthread_attr_setschedparam(&attr,&param); //设置优先级
        //----创建线程----
        pthread_create(&pid,&attr,run,NULL);
        //----销毁线程属性----    
    
        //----等待线程结束----
        pthread_join(pid,NULL);
        return 0;
    }
