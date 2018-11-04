#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
int main(int argc,char **argv){
    if(access(argv[1],0)) {
         printf("------ err=%d,errstr=%s\n",errno,strerror(errno));
         return -1;
    }
    int fd=open(argv[1],O_RDWR);
    if (fd<0){
         printf("errno= %s\n",strerror(errno));
         return -1;
    }
    struct stat st;
    stat(argv[1],&st);
    int size=st.st_size;
    //---------------------------
    char *buf=(char *)malloc(size+1);
    bzero(buf,size+1);
    size=read(fd,buf,size);
    //---------------------------
    int i,j;
char tmp;
    for(i=0;i<size;i++){
       for(j=i;j<size;j++){
           if (buf[i] >buf[j]){
              tmp=buf[i];
              buf[i]=buf[j];
              buf[j]=tmp;
           }
       }
    }
    //----------------------------
    size=write(fd,buf,size);
    close(fd);
    return 0;
}
