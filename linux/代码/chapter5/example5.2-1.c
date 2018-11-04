#include <stdio.h>
#include <errno.h> //ÏµÍ³´íÎó
int main(int argc,char **argv){
    int err=mkdir(argv[1],0666); //0666
    if (err==-1){
        printf("----- mkdir err no=%d,str=%s\n",errno,strerror(errno));
  }
    return 0;
}
