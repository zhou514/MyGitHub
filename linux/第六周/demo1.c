//文件I/O编程
//ls -l
//drwxr-xr-x 2 root root 4096 2018-10-15 1111
//drwxr-xr-x 文件的类型和文件权限
/** 文件类型  
 *  -普通文件，存各种数据
 *  d目录文件，存结构体，结构体内部标识这个目录中的文件名称信息
 *  l链接，（硬链接，软链接）软链接称为链接文件
 *  c字符设备 
 *  b块设备 所有存储类的驱动都称为块设备，包含扇区处理
 *  p管道设备 是内核内存模拟的通道
 * /
 /** 文件权限
  *  r 可读  二进制表示  100  -> 十进制 4
  *  w 可写             010            2
  *  x 可执行           001            1
  *  - 无操作，二进制    000          0
  * 
  * 
  * rwxr-xr-x
  * u 创建者user
  * g 群组（创建者所属群组）group
  * o 其他人 other
  * 
  * 2 表示文件节点数  
  * 对于当前文件（目录文件）而言，含义：表示当前文件夹中的文件个数
  * ln 默认创建硬链接         ln -s
  * /
  
  /** 目前文件
   *  "." 表示当前目录（工作目录）
   *  ".." 表示上级目录（父目录）
   *  用户目录（admin）
   *  绝对路径 ： 从根目录开始
   *  相对路径 ： ../../Word配套资料/第1章
   * /

//目录操作
//创建目录
//表头文件
#include <sys/stat.h>
//定义函数
int mkdir(const char *path, mode_t mode);
path:目录名
mode:模式，即访问权限
（
    S_IRUSER 属主可读权限
    S_IWUSER 属主可写权限
    S_IXUSER
    S_IRGRP
    S_IWGRP
    S_IXGRP
    S_IROTH
    S_IWOTH
    S_IXOTH
）
S_IRUSER | S_IWUSER 
0777 0666

创建目录
#include <stdio.h>
#include <sys/stat.h>
#include <errno.h> 

int main(int argc, char **argv){
    int err = mkdir(argv[1],0666);
    if(err == -1)
        printf("mkdir errno = %d",errno);
    return 0;
}

int rmdir(const char *path)
//只能删除空目录

// 获取当前目录及执行目录
char *gecwd(char *buf, size_t size)
buf: 保存当前目录的内存地址
size：为内存大小

// 获取当前目录
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char **argv){
    char dir[256];
    getcwd(dir,256)
    printf("-----%s",dir);

    return 0;
}


// 获取程序运行路径，即应用程序存放的位置
#include <unistd.h>

int readlink(const char *path, char *buf, size_t bufsiz);
path : 符号链接，在linux中执行程序都用"/proc/self/exe/"符号链接
buf 用来写入正在执行的文件名的内存
bufsiz 指明buf的大小

#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char **argv){
    char dir[256] = {0};
    int err = readlink("/proc/self/exe",dir,256);
    if(err == -1) return -1;
    int i;
    for(i = strlen(dir) - 1; i > 0 && dir[i] != '/'; i--);
    dir[i] = 0;
    //打开程序所在目录中的文件
    char filename[256];
    sprintf(filename."%s/%s",dir,argv[1]);
    printf("-----%s\n",filename);
    FILE *fp = fopen(filename,"r");
    if(fp == NULL){
        printf("-------%s\n",strerror(errno));
    }
    return 0;
}