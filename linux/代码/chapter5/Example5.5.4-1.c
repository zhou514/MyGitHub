#include<time.h>
#include <stdio.h>
main(){
    time_t timep;
    struct tm *p;
    time(&timep); //取得时间（秒数）
    printf("time(): %d\n",timep);
    p=localtime(&timep);
    timep=mktime(p);
    printf("time()->localtime()->mktime():%d\n",timep);
}
