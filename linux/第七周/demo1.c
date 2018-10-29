// 获取当前时间
// 表头文件  #include <time.h>
// 定义参数 time_t time(time_t *t);
// 返回从标准时间点到现在所经过的秒数；若指针t不为空，则函数返回值存在指针t所指向的内存中
#include <time.h>
#include <stdio.h>
main()
{
    /* code */
    int seconds = time((time_t*)NULL);
    printf("%d\n",seconds);
    return 0;
}

