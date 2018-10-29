// 将时间结构数据转换成经过的秒数
// time.h
// time_t mktime(struct tm * timeptr);
// mktime() 将参数timeptr所指向的tm结构数据转换成从公元1970年1月1日0时0分0秒到现在的UTC时间所经过的秒数

#include <time.h>
#include <stdio.h>

main()
{
    time_t timep;
    struct tm *p;
    time(&timep);
    printf("time(): %d\n",timep);
    p = localtime(&timep);
    timep = mktime(p);
    printf("time()->localtime()->mktime(): %d",timep);
}
