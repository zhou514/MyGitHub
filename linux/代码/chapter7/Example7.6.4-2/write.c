#include <stdio.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <string.h>
    #include <sys/ipc.h>
    #include <sys/shm.h>
    //write.c 称为服务端
    #define MSIZE  1024
    int main(){
    	  key_t key=ftok("/bin/ls",9);
    	  printf("%d\n",key);
    	  //创建
    	  int shmid=shmget(key,MSIZE,IPC_CREAT | IPC_EXCL | 0666);
    	  if (shmid==-1){
    	  	 printf(" shmget err\n");
    	  	 return 0;
    	  }
    	  //映射
    	  char *p=(char*)shmat(shmid,NULL,0);
    	  if ((int)p==-1){
    	  	 printf("shmat err\n");
    	  	 shmctl(shmid,IPC_RMID,0); //释放
    	  	 return 0;
    	  }
    	  strcpy(p,"钓鱼岛是我们的\n");
    	  sleep(10);
    	  //解除映射
    	  shmdt(p);
    	  //释放
    	  shmctl(shmid,IPC_RMID,0);
    	  return 0;
    }
