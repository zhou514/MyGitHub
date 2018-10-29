#ifndef AO_OSS_H
#define AO_OSS_H
#include <linux/soundcard.h>

//声卡属性
#define CMD_SET_AOINFO 0x00000001  //设置音频信息
#define CMD_GET_AOINFO 0x00000002  //获取音频信息
struct TAO_INFO{
    int speed;     //采样频率  默认44100
    int channels;  //采样频率  默认双声道
    int format;    //采样频率  默认16位
};
#define CMD_SET_PLAYVOL 0x00000003  //设置播放音量
#define CMD_GET_PLAYVOL 0x00000004  //获取播放音量
#define CMD_SET_RECODEVOL 0x00000005  //设置录音音量
#define CMD_GET_RECODEVOL 0x00000006  //获取录音音量

struct TAO_DEV{
    //函数功能：打开设备
    //返回值  ：int 失败 -1 ，成功 0
    int (*open)(char *devname,int flag);
    //函数功能：设置或获取相关信息
    //函数参数：cmd 设置指令
    //         val 设置值的内存地址
    //返回值  ：int 失败 -1 ，成功 0
    int (*ioctl)(int cmd,void *val);
    //函数功能：向dsp写数据播放声音
    //函数参数：data ,音频数据
    //          len   音频数据长度 建议为4096
    //返回值  ：int 失败 -1 ，成功 0
    int (*write)(void *data,int len);
    //函数功能：从dsp获取数据
    //函数参数：data ,音频数据地址
    //          len   音频数据长度
    //返回值  ：int 失败 -1 ，成功 0
    int (*read)(void *data,int len);
    //函数功能：关闭设备
    //返回值  ：int 失败 -1 ，成功 0
    int (*close)();
};

extern struct TAO_DEV aodev_interface;

#endif // AO_OSS_H
