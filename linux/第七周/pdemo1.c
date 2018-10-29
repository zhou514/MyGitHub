typedef struct task_struct{
    int pid; //进程ID，用来标识进程
    unsigned long state; //进程状态，描述当前进程运行状态
    unsigned long count; //进程时间片数
    unsigned long timer; //进程的休眠时间
    unsigned long priority; //进程默认优先级，进程时间片数和优先级都属于进程调度信息
    unsigned long content[20]; //进程执行现场保存区，包含当前进程使用的操作寄存器，状态寄存器和栈指针寄存器等
}PCB;