创建进程
1.system函数调用 
    用于执行shell命令
    #include <stdlib.h>
        int system(const char *command)
            command为Linux指令
            返回值 
                -1 表示错误
                0 表示调用成功但是没有出现子进程
                >0 表示成功退出的子进程ID
        调用/bin/sh时失败则返回127
        若command为空指针（NULL），则返回非零值
        system("ls -l");
        system("./mplay");
2.exec系列函数调用
    #include <unistd.h>
    int execl(const char *path, const char *arg,...);
    int execle(const char *path, const char *arg, ..., char* const envp[]);
    int execv(const char *path, char* const arg[]);
    int execve(const char *filename, char *const argv[], char *const envp[]);
    int execvp(const char *file, char* const argv[])
    int execlp(const char *file, const char *arg, ...)
    参数
        path file 表示要执行程序的包含路径的文件名
        arg为参数列表，中间用逗号隔开
        argv为参数列表；
        envp为环境变量参数
    返回值
        调用失败，才返回-1，从原程序的调用点接着往下调用
    exec函数系列的作用主要是根据指定的文件名找到可执行文件，并用它来取代调用进程的内容，不创建进程，被调用者成为当前进程
    