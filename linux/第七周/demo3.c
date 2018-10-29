// 取得当地目前时间和日期
// time.h
// struct tm *localtime(const time_t* timep); 
// localtime() 将timep所指向的time_t结构中的信息转换成真实世界所使用的时间日期表示方法
// 然后将结果值由tm返回

#include <time.h>
#include <stdio.h>

main()
{
    /* code */
    char *wday[] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
    time_t timep;
    struct tm *p;
    time(&timep);
    p = localtime(&timep);
    printf("%d-%d-%d ",(1900+p->tm_year),(1+p->tm_mon),p->tm_mday);
    printf("%s %d:%d:%d\n",wday[p->tm_wday],p->tm_hour,p->tm_min,p->tm_sec);
    return 0;
}
