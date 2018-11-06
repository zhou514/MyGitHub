// //标准流管道
// 操作流程：
// popen->fread->pclose

// 1.创建管道
// #include <stdio.h>
//     FILE *popen(const *command,const char *type);
//     command 为用双引号括起来的指令
//     type 可为w或r ，通常用r

// 2.读取数据
// fread

// 3.关闭管道
// int pclose(FILE *stream);

//读取指令结果
#include <stdio.h>
int main(int argc, char **argv)
{
    /* code */
    FILE *fp = popen("date","r");
    if(fp == NULL){
        printf("popen err\n");
        return 0;
    }
    char buf[256] = {0};
    fread(buf,256,1,fp);
    pclose(fd);
    printf("--%s\n",buf);
    return 0;
}
