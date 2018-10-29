// 取得当前时间
// #include <sys/time.h>
// #include <unistd.h>
// int gettimeofday(struct timeval *tv,struct timezone *tz);
// gettimeofday() 把目前的时间由tv所指的结构返回，当地时区的信息则放到tz所指的结构中
// 返回值 0或1  0成功  1失败

// struct timeval
// {
//     long tv_sec; //秒
//     long tv_usec; //微秒
// };


// struct timezone
// {
//     int tz_minuteswest; //和Greenwich时间差了多少分钟
//     int tz_dsttime; //日光节约时间的状态
// };

#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

main()
{
    struct timeval tv;
    struct timezone tz;
    gettimeofday(&tv, &tz);
    printf("tv_sec;%d\n",tv.tv_sec);
    printf("tv_usec;%d\n",tv.tv_usec);
    printf("tz_minuteswest;%d\n",tz.tz_minuteswest);
    printf("tz_dsttime;%d\n",tz.tz_dsttime);
    return 0;
}