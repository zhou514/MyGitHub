// 将时间和日期用ASCII码格式表示
// char *asctime(const struct tm *timeptr);

#include <time.h>
#include <stdio.h>

main(){
    time_t timep;
    time(&timep);
    printf("%s",asctime(gmtime(&timep)));
}
