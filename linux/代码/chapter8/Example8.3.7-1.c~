#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
sem_t sem;  //定义信号量
void * run1(void *buf){
    int i=0;
    while(1){
       sem_wait(&sem); //p操作，信号量减1 如果信号量为0则阻塞
       printf("run1 -----id=%u,i=%d\n",pthread_self(),i++);
       sem_post(&sem); //v操作，信号量加1
       usleep(1);
    }
}
void * run2(void *buf){
    int i=0;
    while(1){
       sem_wait(&sem); //p操作，信号量减1 如果信号量为0则阻塞
       printf("run2 -----id=%u,i=%d\n",pthread_self(),i++);
       sleep(2);
       sem_post(&sem); //v操作，信号量加1
       usleep(1);
    }
}
int main(int argc,char **argv){
    pthread_t pid1,pid2;
    //----创建线程----
    sem_init(&sem,0,1);
    pthread_create(&pid1,NULL,run1,NULL);
    pthread_create(&pid2,NULL,run2,NULL);
    //----等待线程结束
    pthread_join(pid1,NULL);
    pthread_join(pid2,NULL);
    sem_destroy(&sem);
    return 0;
}
