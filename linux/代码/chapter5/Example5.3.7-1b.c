#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <linux/soundcard.h>
#include <alsa/asoundlib.h>

int main(int argc,char **argv){
        //打开文件
        int fd=open(argv[1],O_RDONLY);
        if (fd==-1){
           printf("----- open err=%s\n",strerror(errno));
           return -1;
        }
        char type[5]={0};
        short channel;
        short bit;
        int sample;
        lseek(fd,0x08,0);
        read(fd,type,4);
        lseek(fd,0x16,0);
        read(fd,&channel,2);
        read(fd,&sample,4);
        lseek(fd,0x22,0);
        read(fd,&bit,2);
        close(fd);
        printf("--- %s,%d,%d,%d\n",type,channel,sample,bit);
    } 
