#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <pthread.h>
#include <errno.h>
#include "ao_out.h"
//#include "audio_out.h"
struct wav_head{
   char riff[4];
   long len;  //文件长度
   char sign[4]; //WAVE标志
   char fmt[4];  //fmt标志 
   long tmp;     //保留
   short pcm;    //0x10 为PCM
   short channels; //声道数
   long  speed;    //采样数
   long  rate;      //channels * speed * format/8
   short bps;       //channels * format/8
   short format;    //采样位数
   char  data[4];   //data标记
   long  datalen;   //数据长度
};

struct wav_head head={"RIFF",44,"WAVE","fmt ",0,0x10,1,22050,0,0,1,"data",0};
int fd;
int state=1;
int len=0; 
pthread_t ao_pid;
void *aodev_pthread(void *arg){
    char buffer[4096];
    while(state){
        int size=aodev_interface.read(buffer,4096);
        size=write(fd,buffer,size);
        len+=size;
        printf("size=%d\n",size);
        usleep(100);
    }
}

int main(int argc,char **argv){
#if 0
    char *filename=argv[1];
    //extern AO_AUDIO_DRIVER audio_oss;
    int err= aodev_interface.open("/dev/dsp",1);
    if (err==-1) return -1;
    struct TAO_INFO info;
    info.channels=1;
    info.speed=8000;
    info.format=8;
    if (argc==5){
        info.speed=atoi(argv[2]);
        info.format=atoi(argv[3]);
        info.channels=atoi(argv[4]);
    }
    aodev_interface.ioctl(CMD_SET_AOINFO,&info);
    head.channels=info.channels;
    head.speed=info.speed;
    head.format=info.format;
    head.rate=info.channels * info.speed * info.format/8;
    head.bps=(info.channels *info.format/8);

    printf("--------------------------2 speed=%d,format=%d,chan=%d, filename=%s\n",
                                        head.speed,head.format,head.channels,filename);
    fd=open(filename,O_CREAT|O_RDWR);
    if (fd==-1) {
        printf("open %s err,%s\n",argv[1],strerror(errno));
        aodev_interface.close();
        return -1;
    }
    printf("--------------------------3\n");
    write(fd,&head,sizeof(head));    
    pthread_create(&ao_pid,NULL,aodev_pthread,NULL);

    char cmd[256];
    while(1){
       scanf("%s",cmd);
       printf("-------------------%s\n",cmd);
       if (strcmp(cmd,"q")==0) break;
    }    
    state=0;
    pthread_join(ao_pid,NULL);
    lseek(fd,0x04,0);
    int filesize=len+44;
    write(fd,&filesize,4);
    lseek(fd,0x28,0);
    write(fd,&len,4);

    close(fd);
    aodev_interface.close();
#endif      
#if 1
    int err;
    if (argc==1) return 0;
    char filename[256];
    strcpy(filename,argv[1]);
    printf("--------------------------filename= %s \n",filename);
    err=aodev_interface.open("/dev/dsp");
    if (err==-1) return -1;
    printf("--------------------------1\n");
    struct TAo_Info info;
    aodev_interface.ioctl(CMD_GET_AOINFO,&info);
    head.channels=info.channels;
    head.speed=info.speed;
    head.format=info.format;
    head.rate=info.channels * info.speed * info.format/8;
    head.bps=(info.channels *info.format/8);
    printf("--------------------------2 speed=%d,format=%d,chan=%d, filename=%s\n",
                                        head.speed,head.format,head.channels,filename);
    fd=open(filename,O_CREAT|O_RDWR);
    if (fd==-1) {
        printf("open %s err,%s\n",argv[1],strerror(errno));
        aodev_interface.close();
        return -1;
    }    
    printf("--------------------------3\n");
    write(fd,&head,sizeof(head));    
    pthread_create(&ao_pid,NULL,aodev_pthread,NULL);
    char cmd[256];
    while(1){
       scanf("%s",cmd);
       printf("-------------------%s\n",cmd);
       if (strcmp(cmd,"q")==0) break;
    }    
    state=0;
    pthread_join(ao_pid,NULL);
    lseek(fd,0x04,0);
    int filesize=len+44;
    write(fd,&filesize,4);
    lseek(fd,0x28,0);
    write(fd,&len,4);
    close(fd);
    aodev_interface.close();  
#endif 
}
