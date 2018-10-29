#include<stdio.h>
#include "lib.h"
//#include "mplay.h"
int curstate,sq;
void fun(int state,int val)
{     
      curstate=state;
      printf("state=%d,val=%d\n",state,val);
}
int main(int argc,char **argv)
{
  printf("********************************************************\n");
  printf("p 播放      q 暂停    r 录音     s 停止      d 销毁     \n");
  printf("f 播放位置  n 前进    t 后退     e 设置音量  h 获取音量 \n");
  printf("********************************************************\n");
  char buf[23];
   while(1) {
      if(sq==-1) break;
      scanf("%s",buf);
      if(strcmp(buf,"p")==0) {
      if(curstate==3) {
       minit(NULL);
       mplay(NULL); 
             }
       else {
             minit(fun);
             mplay(argv[1]);
               }
         }  
     else if(strcmp(buf,"s")==0)
         sq=mstop();
       // else if(strcmp(buf,"r")==0) 
         else if(strcmp(buf,"q")==0)
           mpause();   
        else if(strcmp(buf,"f")==0)
          {
         int a=msetpos();
          printf("--%d\n",a);
          }
       else if(strcmp(buf,"n")==0)
       {
           fastforward(900000);
       } 
       else if(strcmp(buf,"t")==0)
           fastretreat(-500000);
       else if(strcmp(buf,"e")==0)
           {
            mpause();
            int b,c;
            scanf("%d %d",&b,&c);
            setvolume(b,c);
            }
       else if(strcmp(buf,"h")==0)
           {
             mpause();
             int vol,d,f; 
             getvolume(&d,&f);
             vol=f<<8 | d;
             printf("%d %d %d",d,f,vol);
            }
        else if(strcmp(buf,"r")==0)
             mrecode(argv[1]);
 }
}
