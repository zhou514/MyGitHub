// 线程生命周期：就绪，运行，阻塞，终止
// 就绪：线程能够运行，但是在等待可用的处理器，可能是刚刚启动，或从阻塞状态中恢复，或被其他线程抢占
// 运行：正在工作；单处理器系统，只能有一个线程处于运行状态；多处理器，可能有多个线程处于运行状态
// 阻塞：线程由于等待处理器的处理，造成无法运行的情况；条件变量的改变，加锁互斥量或I/O操作结束
// 终止：线程从线程函数中返回，或调用pthred_exit，或被取消，或随进程终止而终止。

// Linux系统中 多线程遵循POSIX线程接口，称pthread 
// #include <pthread.h>
// 连接时需要使用库libpthread.a
// Linux系统下pthread是用过系统调用clone()来实现

// 1.线程创建
// 函数pthread_create,pthread_join,pthread_fcntl
// 头文件 #include <pthread.h>
// 函数定义 int pthread_create(pthread_t *restrict tidp,const pthread_attr_t *restrict attr,void *(*start_rtn)(void),void *restrict arg);
// tidp 指向线程标识符的指针，如果线程创建成功，返回线程ID
// attr 用来指定线程的属性，NULL表示使用默认属性
// start_rtn 函数指针，线程创建后需要调用的函数，称为线程函数
// arg 传递给线程函数的参数
// 返回值 0成功 发生错误时返回错误码
// 由于pthread的库不是Linux系统的库，在编译时要加上： #gcc filename -l pthread

#include <pthread.h>
void *run(void *buf){
    int i = 0;
    while(i < 10){
        printf("-------------pthread id = %d, i = %d\n",pthread_self(),i);
        usleep(1000000);
        i++;
    }
    return (void*)i;
}
int main(int argc,char **argv){
    pthread_t tid;
    pthread_create(&tid,NULL,run,NULL); //创建线程
    void *val; //val 指针变量
    ptread_join(tid,&val);
    printf("%d\n",val);
}

// 2.退出线程
// 例一：
#include <pthread.h>
void *run(void *buf){
    int i=0;
        while(i<10){
          printf("----------pthread id =%d,i=%d\n", pthread_self(),i);

          usleep(1000000);
          if (i==5) pthread_exit(i); //相当于 return i;
          i++;
       }
       return NULL;
     }
     
int main(int argc,char **argv){
         pthread_t tid;
         pthread_create(&tid,NULL,run,NULL);  //创建线程
         void *val;
			pthread_join(tid,&val);
			printf("---val=%d\n",val);
     			}	

// 例二：
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
void *create(void *arg)
{
    printf("new thread is created ... \n");
    pthread_exit ((void *)8);
}
int main(int argc,char *argv[])
{
    pthread_t tid;
    int error;
    void *temp;
    error = pthread_create(&tid, NULL, create, NULL);
    printf("main thread!\n");
    if( error )
    {
        printf("thread is not created ... \n");
        return -1;
    }
    error = pthread_join(tid, &temp);
    if( error )
    {
        printf("thread is not exit ... \n");
        return -2;
    }
      printf("thread is exit code %d \n", (int )temp);
    return 0;
}


// 3.线程等待
// （1）：
#include <pthread.h>
void *run(void *buf){
       int i=0;
       while(i<10){
          printf("----------pthread id =%d,i=%d\n", pthread_self(),i);
          usleep(1000000);
          i++;
       }
     }
     
     int main(int argc,char **argv){
         pthread_t tid;
         pthread_create(&tid,NULL,run,NULL);  //创建线程
         sleep(1);
     }


// （2）：
#include <pthread.h>
void *run(void *buf){
       int i=0;
       while(i<10){
          printf("----------pthread id =%d,i=%d\n", pthread_self(),i);
          usleep(1000000);
          if (i==5) return NULL;  //return的作用是结束函数
          i++;
       }
     }
     
     int main(int argc,char **argv){
         pthread_t tid;
         pthread_create(&tid,NULL,run,NULL);  //创建线程
         pthread_join(tid,NULL);
     }

// （3）：
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
void *thread(void *str)
{
    int i;
    for (i = 0; i<4; ++i)
    {
        sleep(2);
        printf("This in the thread : %d\n", i);
    }
    return NULL;
}
int main()
{
    pthread_t pth;
    int i;
    int ret = pthread_create(&pth, NULL, thread,(void *)(i));
    pthread_join(pth, NULL);
    printf("123\n");
    for (i = 0; i < 3; ++i)
    {
        sleep(1);
        printf( "This in the main : %d\n" , i );
    }
     return 0;
}


// 4.线程标识获取
#include <stdio.h>
#include <pthread.h>
#include <unistd.h> /*getpid()*/
void *create(void *arg)
{
printf("New thread .... \n");
printf("This thread's id is %u \n",(unsigned int)pthread_self());
printf("The process pid is %d  \n",getpid());
    return (void *)0;
} 
int main(int argc,char *argv[])
{
    pthread_t tid;
    int error;
    printf("Main thread is starting ... \n");
    error = pthread_create(&tid, NULL, create, NULL);
    if(error)
    {
        printf("thread is not created ... \n");
        return -1;
    }
    printf("The main process's pid is %d  \n",getpid());
    sleep(1);
    return 0;
}


// 5.线程清除
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
void *clean(void *arg)
{
    printf("cleanup :%s  \n",(char *)arg);
    return (void *)0;
}
void *thr_fn1(void *arg)
{
    printf("thread 1 start  \n");
    pthread_cleanup_push( (void*)clean,"thread 1 first handler");
    pthread_cleanup_push( (void*)clean,"thread 1 second hadler");
    printf("thread 1 push complete  \n");
    if(arg)
    {
        return((void *)1);
    }
    pthread_cleanup_pop(0);
    pthread_cleanup_pop(0);
    return (void *)1;
}
void *thr_fn2(void *arg)
{
    printf("thread 2 start  \n");
    pthread_cleanup_push( (void*)clean,"thread 2 first handler");
    pthread_cleanup_push( (void*)clean,"thread 2 second handler");
    printf("thread 2 push complete  \n");
    if(arg)
    {
        pthread_exit((void *)2);
    }
    pthread_cleanup_pop(0);
    pthread_cleanup_pop(0);
    pthread_exit((void *)2);
}
int main(void)
{
    int err;
    pthread_t tid1,tid2;
    void *tret;
    err=pthread_create(&tid1,NULL,thr_fn1,(void*)1);
    if(err!=0)
    {
        printf("error .... \n");
        return -1;
    }
    err=pthread_create(&tid2,NULL,thr_fn2,(void*)1);
    if(err!=0)
    {
        printf("error .... \n");
        return -1;
    }
    err=pthread_join(tid1,&tret);
    if(err!=0)
    {
        printf("error .... \n");
        return -1;
    }
    printf("thread 1 exit code %d  \n",(int)tret);
    err=pthread_join(tid2,&tret);
    if(err!=0)
    {
        printf("error .... ");
        return -1;
    }
    printf("thread 2 exit code %d  \n",(int)tret);
    return 1;
}


// 线程清除
#include <pthread.h>
void *run(void *buf){
        int i=0;
while(1){
          printf("----------pthread id =%d,i=%d\n", pthread_self(),i);
          usleep(1000000);
          i++;
        }
        return NULL;
     }
     int main(int argc,char **argv){
     pthread_t tid;
     pthread_create(&tid,NULL,run,NULL);  //创建线程
     sleep(5);
     pthread_cancel(tid);
pthread_join(tid,NULL);
     }
