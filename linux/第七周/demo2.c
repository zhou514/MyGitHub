// 获取目前时间和日期
// 表头  #include <time.h>
// 函数 
// struct tm*gmtime(const time_t*timep)
// {
//     /* data */
// };
// 说明 gmtime()将参数timep所指向的time_t结构中的信息转换成现实世界中的日期，结果由tm返回
// struct tm(){
//     int tm_sec;  //代表当前的秒数
//     int tm_min; //分
//     int tm_hour;//时
//     int tm_mday;//日
//     int tm_mon;//月
//     int tm_year;//年
//     int tm_wday; //星期
//     int tm_yday; //从今年1月1日起计算到今天的天数
//     int tm_isdst; 
// };

#include <time.h>
#include <stdio.h>
main()
{
    char *wday[] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
    time_t timep;
    struct tm *p;
    time(&timep);
    p = gmtime(&timep);
    printf("%d-%d-%d ",(1900+p->tm_year),(1+p->tm_mon),p->tm_mday);
    printf("%s %d:%d:%d\n",wday[p->tm_wday],p->tm_hour,p->tm_min,p->tm_sec);
}