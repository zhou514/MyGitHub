#include <pthread.h>
void *run(void *buf){
       int i=0;
       while(i<10){
          printf("----------pthread id =%d,i=%d\n", pthread_self(),i);
          usleep(1000000);
          if (i==5) return NULL;  //return的作用是结束函数
          i++;
       }
     }
     
     int main(int argc,char **argv){
         pthread_t tid;
         pthread_create(&tid,NULL,run,NULL);  //创建线程
         pthread_join(tid,NULL);
     }
