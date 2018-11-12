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

// 3.线程等待

// 4.线程标识获取

// 5.线程清除