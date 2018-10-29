#include "system_sem.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <fcntl.h>

//初始化信号量
int init_sem(int key,int val,int semflg){
    union semun sem_union;
    sem_union.val=val;
    int sem_id=semget(key,1,semflg); //创建信号量
    if (sem_id!=-1){
       if (semctl(sem_id,0,SETVAL,sem_union)==-1) return -1; //设置信号量初始值 
    }
    return sem_id;
}

//销毁信号量
int del_sem(int sem_id){
    union semun sem_union;
    int err=semctl(sem_id,0,IPC_RMID,sem_union);
    if (err==-1) exit(-1);
    return 0;
}
//p操作 信号量减1
int wait_sem(int sem_id){
    struct sembuf sem={0,-1,SEM_UNDO}; //填写结构，指明信号量减1
    int err=semop(sem_id,&sem,1); //调用信号操作，如果信号量当前为0，则阻塞
    if (err==-1) exit(0);
    return 0;
}
//v操作 信号量加1
int post_sem(int sem_id){
    struct sembuf sem={0,1,SEM_UNDO};
    int err=semop(sem_id,&sem,1);
    if (err==-1) exit(0);
    return 0;
}
