// fork分叉函数调用
// #include <unistd.h>

// (1)获取进程ID
//     pid_t getpid(void);  //获取当前进程ID
//     pid_t getppid(void); //获取父进程ID
// (2)创建子进程的函数：
//     pid_t fork(void);
//     返回值 失败时返回-1
//             成功时返回进程ID
// //

// 用fork创建子进程
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int main(int argc,char **argv){
    char buf[256];
    pid_t pid = fork(); //用fork创建子进程后，子进程具有与父进程相同的代码
    //pid 为-1 ，失败；目前只有一个进程
    if(pid == -1) return 0;
    //如果创建成功，则父进程中都会从fork 执行代码
    //为区分代码是从子进程中执行还是父进程中执行，用pid来判断
    else if(pid == 0){ //指定子进程要执行的代码
        strcpy(buf,"我是子进程");
        int i,a = 5;
        for(i = 0;i < 5;i++){
            printf("son------ %d\n",i);
            sleep(1);
        }
    }
    else{ //指定父进程要执行的代码
        strcpy(buf,"我是父进程");
        int i,a = 10;
        for(i = 5;i < a;i++){
            printf("parent------ %d\n",i);
            sleep(3);
        }
    }
    //父子进程都会执行的代码
    printf("---%s,my pid = %d\n",buf,getpid());
    return 0;
}