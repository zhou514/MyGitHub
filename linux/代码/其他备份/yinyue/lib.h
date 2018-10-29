#define LIB_H
#ifndef LIB_H
extern int minit(handler_t handler);
//播放函数 参数为wav音频文件名，如果暂停后继续播放，则可输入NULL
extern int mplay(char *name);
//录音函数 参数为wav音频文件名
extern int mrecode(char *name);
//暂停  可暂停当前录音或播放
extern int mpause();
//停止  可停止当前录音或播放
extern int mstop();
//设置播放位置 参数为秒
extern int msetpos(int t);
//前进 参数为秒
extern int fastforward(int diff);
//后退 参数为秒
extern int fastretreat(int diff);
//设置音量 音量值范围 0-100
extern int fastretreat(int diff);
//设置音量 音量值范围 0-100
extern int setvolume(int left,int right);
//获取音量 音量值范围 0-100
extern int getvolume(int *left,int *right);
//销毁
extern int destory();



#endif
