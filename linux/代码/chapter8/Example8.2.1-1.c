#include <pthread.h>
void *run(void *buf){
       int i=0;
       while(i<10){
          printf("----------pthread id =%d,i=%d\n", pthread_self(),i);
          usleep(1000000);
          i++;
       }
       return (void*)i;
     }
         int main(int argc,char **argv){
         pthread_t tid;
         pthread_create(&tid,NULL,run,NULL);  //创建线程
         void *val; //val是变量,指针变量本身就是无符号整型变量
         pthread_join(tid,&val);
         printf("%d\n",val);
     }
