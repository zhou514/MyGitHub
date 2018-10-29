#include <stdio.h>
    #include <pthread.h>
    char str[1024];
    pthread_mutex_t mutex;
    pthread_cond_t  cond;
    int count=0;
    void *run1(void *buf){
        while(1){
          pthread_cond_wait(&cond,&mutex);
          count-=2;
          sprintf(str,"run-----------1");
          printf("%s,count=%d\n",str,count);
          sleep(5);
          usleep(1);
        }
    }
    void *run2(void *buf){
        while(1){
          sprintf(str,"run-----------2");
          printf("%s, count=%d\n",str,count);
          sleep(2);
          if(count%10==0) pthread_cond_signal(&cond);
          count++;
          usleep(1);
        }
    }
    int main(int argc,char **argv){
        pthread_mutex_init(&mutex,NULL);
        pthread_cond_init(&cond,NULL);
        pthread_t tid1,tid2;
        pthread_create(&tid1,NULL,run1,NULL);
        pthread_create(&tid2,NULL,run2,NULL);
        pthread_join(tid1,NULL);
        pthread_join(tid2,NULL);
        pthread_cond_destroy(&cond);
        pthread_mutex_destroy(&mutex);
    }
