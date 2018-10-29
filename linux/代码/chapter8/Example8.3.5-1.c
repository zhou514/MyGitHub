   #include <stdio.h>
    #include <pthread.h>
    
    char str[1024];
    pthread_mutex_t mutex;
    
    void *run1(void *buf){
        while(1){
          pthread_mutex_lock(&mutex);
          sprintf(str,"run-----------1");
          printf("%s\n",str);
          sleep(5);
          pthread_mutex_unlock(&mutex);
          usleep(1);
        }
    }
    
    void *run2(void *buf){
        while(1){
          pthread_mutex_lock(&mutex);
          sprintf(str,"run-----------2");
          printf("%s\n",str);
          sleep(2);
          pthread_mutex_unlock(&mutex);
          usleep(1);
        }
    }
    int main(int argc,char **argv){
        pthread_mutex_init(&mutex,NULL);
        pthread_t tid1,tid2;
        pthread_create(&tid1,NULL,run1,NULL);
        pthread_create(&tid2,NULL,run2,NULL);
        
        
        pthread_join(tid1,NULL);
        pthread_join(tid2,NULL);        
        pthread_mutex_destroy(&mutex);
    }
