// 设置目前时间
// #include <sys/time.h>
// #include <unistd.h>
// int settimeofday(const struct timeval *tv,const struct timezone *tz);
// settimeofday() 把目前时间设置成由tv所指向的结构信息，当地时区信息则设置成tz所指的结构
// 返回值 0或1 0成功 1失败
// 只能由root用户才能操作