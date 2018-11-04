   #include <stdio.h>
   #include <stdlib.h>
   #include <string.h>
   #include <unistd.h>
   #include <sys/wait.h>
   int main(int argc,char **argv){
   	  int fd[2]; //描述符 0 读  1写
   	  int err=pipe(fd);
   	  if (err==-1){
   	  	  printf("pipe err\n");
   	  	  exit(0);
   	  }
   	  pid_t pid=fork();
   	  if (pid==-1) exit(0);
   	  else if (pid==0){ //子进程
   	  	 close(fd[1]);
   	  	 char buf[256]={0};
   	  	 int size=read(fd[0],buf,256);
   	  	 if (size >0) printf("son ---- %s\n",buf); //如果管道为空时,则关闭管道则read返回0 
   	  	 else printf("son read err\n");
   	  	 close(fd[0]);
   	  	 exit(0);
   	  }
   	  else if (pid >0){ //父进程
   	     close(fd[0]);
   	     char *str="1234567890";
   	     int size=write(fd[1],str,strlen(str));
   	     sleep(5);
   	     close(fd[1]);  
   	     wait(NULL);   	     
   	     exit(0);
   	  }
   }
