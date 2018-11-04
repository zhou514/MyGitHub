   //read.c 称为服务端
#include <stdio.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <string.h>
    #include <sys/ipc.h>
    #include <sys/shm.h>

    int main(){
    		key_t key=ftok("/bin/ls",9);
    	  printf("%d\n",key);
    	  //获取
    	  int shmid=shmget(key,0,0);
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
    	  struct shmid_ds shmbuf;
        shmctl(shmid,IPC_STAT,&shmbuf);
        int size=shmbuf.shm_segsz;
    	  printf("%d,%s\n",size,p);
    	  
    	  //解除映射
    	  shmdt(p);
    	  
    	  return 0;
}  

