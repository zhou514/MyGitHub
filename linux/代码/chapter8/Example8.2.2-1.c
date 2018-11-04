#include <pthread.h>
void *run(void *buf){
       int i=0;
       while(i<10){
          printf("----------pthread id =%d,i=%d\n", pthread_self(),i);
          usleep(1000000);
          if (i==5) pthread_exit(i); //相当于 return i;
          i++;
       }
       return NULL;
     }
     
     int main(int argc,char **argv){
         pthread_t tid;
         pthread_create(&tid,NULL,run,NULL);  //创建线程
         void *val;
			pthread_join(tid,&val);
			printf("---val=%d\n",val);
     			}	

