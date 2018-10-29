// 将时间和日期以字符串的格式表示
// #inlcude <time.h>
// char *ctime(const time_t *timep);

#include <time.h>
#include <stdio.h>

main()
{
    time_t timep;
    time(&timep);
    printf("%s",ctime(&timep));
}
