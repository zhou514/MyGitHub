#include <stdio.h>
#include <string.h>
#include "mplay.h"
    int curstate;
    int getstate(int state,int val){
        curstate=state;
        printf("---- state =%d，val=%d\n",state,val);
    }
int main(int argc,char **argv){
        char cmd[256];
        while(1){
           scanf("%s",cmd);
           if (strcmp(cmd,"q")==0) break;
           else if (strcmp(cmd,"p")==0){
                if (curstate==2)
                   play(NULL,NULL);
                else {
                   printf("请输入文件名：\n");
                   scanf("%s",cmd);
                   play(cmd,getstate); //播放
                }
           }
           else if (strcmp(cmd,"s")==0)
                stop();
           else if (strcmp(cmd,"z")==0)
                pause();
        }  
   }
