#include<time.h>
#include <stdio.h>
main(){
	int seconds= time((time_t*)NULL);
	printf("%d\n",seconds);
} 
