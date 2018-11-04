#include <pthread.h>
void *run(void *buf){
        int i=0;
while(1){
          printf("----------pthread id =%d,i=%d\n", pthread_self(),i);
          usleep(1000000);
          i++;
        }
        return NULL;
     }
     int main(int argc,char **argv){
     pthread_t tid;
     pthread_create(&tid,NULL,run,NULL);  //创建线程
     sleep(5);
     pthread_cancel(tid);
pthread_join(tid,NULL);
     }
