#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
 int main(int argc,char **argv){
         char dir[256]={0};
         int err=readlink("/proc/self/exe",dir,256);
         if (err==-1) return -1;
         //char *p，*p1=dir;
         //while((p=strstr(p1+1，"/"))！=NULL) p1=p;
         //*p1=0;
         int i;
         for(i=strlen(dir)-1;i>=0 && dir[i]!='/';i--);
         dir[i]=0; 
         //打开程序所在目录中的文件
         char filename[256];
         sprintf(filename,"%s/%s",dir,argv[1]);
         printf("---- %s\n",filename);
         FILE *fp=fopen(filename,"r");
         if (fp==NULL){
            printf("---- %s\n",strerror(errno));
         }
         return 0;
     }
