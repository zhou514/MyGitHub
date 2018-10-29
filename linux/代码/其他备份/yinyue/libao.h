#ifndef LIBAO_H
#define LIBAO_H

typedef enum {dsp,alsa} ao_type_t;
typedef struct AOINFO{
	ao_type_t type; //设备类型编号 
	char *name;     //oss  asla等
	char *author;   //作者
	char *time;     //编写时间	
	char *describe; //模块描述	
} ao_info_t;

typedef struct LIBAO{
  ao_info_t *info;  //模块信息
  int (*open)(char *devname,int flags); //打开设备
  int (*read)(char *buf,int size);  //输入数据
  int (*write)(char *buf,int size); //输出数据
  int (*ioctl)(int cmd,void *data); //控制设备
  int (*close)();  //关闭设备
} ao_t;

//extern ao_t *getdev(ao_type_t type);  
extern ao_t ao_dsp;
#endif
