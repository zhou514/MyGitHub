#include <stdio.h>
#include "libao.h"
static int dsp_fd;
static int dsp_open(char *devname,int flags){ //打开设备
        int dsp_fd=open(devname,flags); 
        return dsp_fd;
        }
static int dsp_read(char *buf,int size){  //输入数据      
       int size1=read(dsp_fd,buf,size);	 
       return size1;
}
 
static int dsp_write(char *buf,int size){ //输出数据
	int sze=write(dsp_fd,buf,size);  
        return sze;
}

static int dsp_ioctl(int cmd,void *data){ //控制设备
	    int ss=ioctl(dsp_fd,cmd,data);
            
}

static int dsp_close(){  //关闭设备
	close(dsp_fd);
        return 0;	
}

ao_info_t dsp_info={
	 0,    //设备类型编号 
	"dsp",   //oss  asla等
	"ztl",  //作者
	"2016-1-29", //编写时间	
	"用于dsp音频设备接口" //块描述	
};

ao_t ao_dsp={
	 &(dsp_info),
   dsp_open,
   dsp_read,
   dsp_write,
   dsp_ioctl,
   dsp_close,
};

