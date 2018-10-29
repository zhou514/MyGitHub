#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/types.h>
#include "system_sem.h"
#define SHMSIZE 4096
int main(int argc,char **argv){
    char *shmbuf;
    int  fd;
    //生成一个主键，尽量保持主键永久不变
    key_t key=ftok("/bin/ls",42);
    //调用信号量初始化函数
    int sem_id=init_sem(key,1,IPC_CREAT | IPC_EXCL |0666);
    if (sem_id==-1){
        printf("init_sem err=%s\n",strerror(errno));
        goto INITSEM_ERR;
    }
    //设置共享区域
    //fd=shm_open("./test.map",O_CREAT | O_RDWR | O_EXCL,0666);
    fd=open("./test.f",O_CREAT | O_RDWR ,0666);
    if (fd==-1){
        printf("open err =%s\n",strerror(errno));
        goto SHMOPEN_ERR;
}
    //内存映射
    shmbuf=mmap(NULL,SHMSIZE,PROT_READ | PROT_WRITE,MAP_SHARED,fd,0);
    if (shmbuf==NULL){
        printf("mmap err =%s\n",strerror(errno));
        goto MMAP_ERR;
    }
    //设定文件长度
    ftruncate(fd,SHMSIZE);

    //写操作
    char buf[256];
    while(1){
       wait_sem(sem_id); //信号量 p操作
       scanf("%s",shmbuf);
       printf("write ---- %s\n",buf);
       if (strcmp(shmbuf,"q")==0) {
          post_sem(sem_id); //信号量 v操作
          break;
       }
       post_sem(sem_id); //信号量 v操作
    }
    //解除映射
    munmap(shmbuf,SHMSIZE);
MMAP_ERR:
    //关闭文件并移除文件
    close(fd);
    //shm_unlink("./test.map");
SHMOPEN_ERR:
    //销毁信号量
    del_sem(sem_id);
INITSEM_ERR:
    return 0;
}
