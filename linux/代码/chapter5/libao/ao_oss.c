#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/soundcard.h>
#include "ao_out.h"

static int audio_fd;
static int mixer_fd;
static struct TAO_INFO aoinfo={
     8000,
     1,
     16
};
static int outburst=512; //每次可读块大小
//函数功能：打开设备
//返回值  ：int 失败 -1 ，成功 0
static int ao_open(char *devname,int flag){
    static audio_buf_info zz;
    //打开设备
    if (flag==1)
       audio_fd=open(devname,O_RDONLY);
    else
       audio_fd=open(devname,O_WRONLY);
    ioctl(audio_fd, SNDCTL_DSP_RESET, NULL);	

    if (audio_fd==-1) {
       printf("open dsp err,%s\n",strerror(errno));
       return -1;
    }
    
    //设置音量
    mixer_fd=open("/dev/mixer",O_RDWR);
    if (mixer_fd==-1){
        printf("open mixer err,%s\n",strerror(errno));
        return 0;
    }
    int vol=100<<8 | 100;
    ioctl(mixer_fd,MIXER_WRITE(SOUND_MIXER_RECLEV),&vol); //设置录音音量
    ioctl(mixer_fd,MIXER_WRITE(SOUND_MIXER_VOLUME),&vol); //设置放音音量
    close(mixer_fd);
    return 0;
}

//函数功能：设置或获取相关信息
//函数参数：cmd 设置指令
//         val 设置值的内存地址
//返回值  ：int 失败 -1 ，成功 0
static int ao_ioctl(int cmd,void *val){
    int vol;
    static audio_buf_info zz;
    int bps,c,err=0;
    if(audio_fd<=0) return -1; 
    switch(cmd){
    case CMD_SET_AOINFO:
    	   memcpy(&aoinfo,val,sizeof(aoinfo));
    	   err=ioctl(audio_fd, SNDCTL_DSP_SETFMT, &aoinfo.format);
    	   err=ioctl(audio_fd, SNDCTL_DSP_CHANNELS, &aoinfo.channels);
    	   c=aoinfo.channels-1;
    	   err=ioctl (audio_fd, SNDCTL_DSP_STEREO, &c);    	   
    	   err=ioctl(audio_fd, SNDCTL_DSP_SPEED, &aoinfo.speed);
           //设置标志位    	   
           fcntl(audio_fd, F_SETFD, FD_CLOEXEC);
           //计算可返回的最大数据长度 
           if(ioctl(audio_fd, SNDCTL_DSP_GETOSPACE, &zz)==-1){  
               int r=0;
               if(ioctl(audio_fd, SNDCTL_DSP_GETBLKSIZE, &r)>0) outburst=r;
           }     
           else {
               outburst=zz.fragsize;
           }
           bps=aoinfo.channels * aoinfo.format *aoinfo.speed/8;     
           printf("ao: forame=%d,chan=%d,rate=%d,bps=%d,outburst=%d\n",
                   aoinfo.format,aoinfo.channels,aoinfo.speed,bps,outburst);
	   break;
    case CMD_GET_AOINFO:
    	   memcpy(val,&aoinfo,sizeof(aoinfo));
    	   break;
    case CMD_SET_PLAYVOL:
    	   mixer_fd=open("/dev/mixer",O_RDWR);
           if (mixer_fd==-1) return -1;
    	   vol=(*(int *)val)<<8 | (*(int *)val);
    	   err=ioctl(mixer_fd,MIXER_WRITE(SOUND_MIXER_VOLUME),&vol);
    	   close(mixer_fd);
    	   break;
    case CMD_GET_PLAYVOL:
    	   mixer_fd=open("/dev/mixer",O_RDWR);
           if (mixer_fd==-1) return -1;
    	   err=ioctl(mixer_fd,MIXER_READ(SOUND_MIXER_VOLUME),&vol);
    	   *(int*)val=vol & 0xff;
    	   close(mixer_fd);
    	   break;
    }
    return err;
}

static int ao_write(void *data,int len){
    if(audio_fd<=0) return -1; 
    if(len==0) return -1;
    if ((outburst >0) && (len>outburst)) {
        len/=outburst;
        len*=outburst;
    }
    //等待回放结束
    if (ioctl(audio_fd, SOUND_PCM_SYNC, 0)==-1) return -1;     
    len=write(audio_fd,data,len);
    return len;
}
 
static int ao_read(void *data,int len){
    if(audio_fd<=0) return -1; 
    if(len==0) return -1;
    if ((outburst >0) && (len>outburst)) {
    	len/=outburst;
    	len*=outburst;
    }
    len=read(audio_fd,data,len);
    return len;
}

static int ao_close(){
    if(audio_fd<=0) return -1; 
    ioctl(audio_fd, SNDCTL_DSP_RESET, NULL);	
    close(audio_fd);
    return 0;
}


struct TAO_DEV aodev_interface={
    ao_open,
    ao_ioctl,
    ao_write,
    ao_read,
    ao_close  
};


