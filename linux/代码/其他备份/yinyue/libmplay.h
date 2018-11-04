#ifndef MPLAY_H
#define MPLAY_H
//枚举，表示各种状态
typedef enum {STOP,PLAY,RECODE,PAUSE,READY} state_t;
//函数指针类型，表示播放状态
/*参数 state  为STOP时，val 为0
              为PLAY时，val 为当前已播时间
              为RECODE时，val为当前已录时间
              为PAUSE时，val为0
              为READY时，val为播放前可播时间
*/
typedef void (*handler_t)(state_t state,int val);

//初始化函数 参数为回调函数句柄
int minit(handler_t handler);
//播放函数 参数为wav音频文件名，如果暂停后继续播放，则可输入NULL
int mplay(char *name);
//录音函数 参数为wav音频文件名
int mrecode(char *name);
//暂停  可暂停当前录音或播放
int mpause();
//停止  可停止当前录音或播放
int mstop();
//设置播放位置 参数为秒
int msetpos(int t);
//前进 参数为秒
int fastforward(int diff);
//后退 参数为秒
int fastretreat(int diff);
//设置音量 音量值范围 0-100
int setvolume(int left,int right);
//获取音量 音量值范围 0-100
int getvolume(int *left,int *right);
//销毁
int destory();

#endif
