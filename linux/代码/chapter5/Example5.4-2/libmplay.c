#include<stdio.h>
#include "libmplay.h"
#include "libao.h"
#include "lib.h"
//#include "libao.c"
#include <linux/ioctl.h>
#include<linux/soundcard.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<errno.h>
#include<malloc.h>
#include <sys/ioctl.h>

typedef struct WAV{
       char riff[4]; //RIFF
       long len;     //文件大小
       char type[4]; //WAVE
       char fmt[4];  //fmt 
       char tmp[4];  //空出的
       short pcm;
       short channel;//声道数
       long sample;  //采样率  speed
       long rate;    //传送速率
       short framesize; //调整数
       short bit;    //样本位数
       char data[4];
        long dblen;   //len-sizeof(struct WAV);  
    }wav_t;
handler_t pp;
int ld,sd,dif;
state_t state;
char mz[23];
//struct ao_t *p=ao_dsp;
int minit(handler_t handler)
{
    //printf("--------8\n"); 
    pp=handler;
}
 void *run(void *arg)
{
 int t=0;
 int i=0;
 while(state) {
   int i=0;
   //while(state==2) usleep(20000);
  // pp(state,i++);
   //sleep(1);    
  char stt[4096];
   ld=open(mz,O_RDONLY);
  wav_t sty;
  int size=read(ld,&sty,44);
 if(size==-1) printf("%s\n",strerror(errno));
   sd=ao_dsp.open("/dev/dsp",O_WRONLY);
  printf("%d\n",sd);
  int a=sty.sample;
  int b=sty.channel;
  int c=sty.bit;
  ioctl(sd,SNDCTL_DSP_SPEED,&a);
  ioctl(sd,SNDCTL_DSP_CHANNELS,&b);
  ioctl(sd,SNDCTL_DSP_SETFMT,&c);
  int size1;
  int len=0;
  printf("----%ld\n",sty.len);
  while((size1=read(ld,stt,4000))!=0) {
     while(state==RECODE) usleep(20000);
      if(dif!=0) lseek(ld,dif,1);
       dif=0;
      // len=lseek(ld,0,1);
         len+=size1;
        t=len/(a*b*c/8);
       pp(state,t);
       //sleep(1);
      // printf("%d\n",size1);
      write(sd,stt,size1);
        }
 printf("------------2\n");
// printf("%d",state);
// close(ld);
// close(sd);        

            //播放函数 参数为wav音频文件名，如果暂停后继续播放，则可输入NUL                 //录音函数 参数为wav音频文件名
   /*while(state) {
    if(state==2) usleep(20000);
    pp(state,i++);
    sleep(1);    
 } */
 }
   //state=0;
  // pp(state,i++);
   close(ld);
   close(sd);
   }
int mplay(char *name)
{
  strcpy(mz,name);
   if(state==0)
  {
   state=PLAY; 
   pthread_t id;
   printf("---------9\n");
   pthread_create(&id,NULL,run,NULL);
     }
  else 
  state=PLAY;
}
int mrecode(char *name)
{
  strcpy(mz,name);
  int fd=open("/dev/dsp",O_RDONLY);
  char buf[4095];
  int speed=44100;
  int bit=16;
  int channel=2;
  wav_t head={"RIFF",44,"WAVE","fmt ",0,0x10,channel,speed,speed*bit*channel/8,channel*bit/8,bit,"data",0};
  int avfd=open(mz,O_CREAT | O_WRONLY);
     if (fd==-1){
                printf("---- open dsp err=%s\n",strerror(errno));
                return -1;
                }
      ioctl(fd,SNDCTL_DSP_SPEED,&speed);
      ioctl(fd,SNDCTL_DSP_CHANNELS,&channel);
      ioctl(fd,SNDCTL_DSP_SETFMT,&bit);
      write(avfd,&head,sizeof(head));
      int len=0,t=0;
  while(1) {
        int size=read(fd,buf,4000);
        write(avfd,buf,size);
        len+=size;
        t=len/(channel*bit*speed/8);
         if(t>5) break;
           }
    int all=len+44;
    lseek(avfd,0x04,0);
    write(avfd,&all,4);
    lseek(avfd,0x28,0);
    write(avfd,&len,4);
    close(fd);
    close(avfd);

//暂停  可暂停当前录音或播放
}
int mpause()
{
   state=RECODE;
   pp(state,0);
   
//停止  可停止当前录音或播放
}
int mstop()
{
  return -1;
//设置播放位置 参数为秒
}
int msetpos(int t)
{
  int sx=lseek(ld,0,1);
  return sx;

//前进 参数为秒
}
int fastforward(int diff)
{
  dif=diff;
//后退 参数为秒
}
int fastretreat(int diff)
{
dif=diff;
//设置音量 音量值范围 0-100
}
int setvolume(int left,int right)
{
   int vol=right<<8 | left;
   ioctl(sd,MIXER_WRITE(SOUND_MIXER_VOLUME),&vol);
//获取音量 音量值范围 0-100
}
int getvolume(int *left,int *right)
{
  int vol1;
  ioctl(sd,MIXER_READ(SOUND_MIXER_VOLUME),&vol1);
  *right=(vol1>>8)&0xff;
  *left=vol1&0xff;
//销毁
}
int destory()
{

}
