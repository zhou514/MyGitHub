  #include <stdio.h>
  #include <sys/stat.h>
  #include <sys/types.h>
  #include <string.h>
  #include <fcntl.h>
  #include <unistd.h>
  
  //server.c 称为服务端
  int main(){
      int err=mkfifo("/tmp/myfifo",0666);
      if (err==-1){
      	printf(" file name is exist\n");
      	return 0;
      }
      int fd=open("/tmp/myfifo",O_WRONLY);
      if (fd==-1){
      	printf(" open err\n");
      	unlink("/tmp/myfifo");
      	return 0;
      }
      char buf[256];
      while(1){
      	scanf("%s",buf);    	
      	int size=write(fd,buf,strlen(buf));
      	printf("write  size =%d,buf=%s\n",size,buf);  
      	if (strcmp(buf,"q")==0) break;  	
      }
      close(fd);
      unlink("/tmp/myfifo");
  }
