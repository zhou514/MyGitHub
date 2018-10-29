#ifndef SYSTEM_SEM_H
#define SYSTEM_SEM_H
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
union semun{
   int val;
   struct semid_ds *buf;
   unsigned short *array;
};
//初始化信号量
extern int init_sem(int key,int val,int semflg);
/* 参数：key 主键键值
         val 信号量的初始值，该值在写进程中设为 1 ，读进程中设为 0
         semflg 创建信号方式
             IPC_CREAT 创建
             IPC_EXCL  防止重建
             mask      权限掩码 如0666
             该参数在写进程中应该设为 IPC_CREAT | IPC_EXCL | 0666 在读进程中应该设为 0
    返回值：信号ID，失败返回-1   
*/
//销毁信号量
extern int del_sem(int sem_id);
//p操作 信号量减1
extern int wait_sem(int sem_id);
//v操作 信号量加1
extern int post_sem(int sem_id);

#endif
