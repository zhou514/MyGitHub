#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

struct STU{
    int runn;
    int num;
    char name[32];
};

void * run(void *buf){
    struct STU *p=buf;
    printf("id=%u,num=%d,name=%s\n",pthread_self(),p->num,p->name);
    int i=0;
    while(i<p->runn){
       printf("------id=%u,i=%d\n",pthread_self(),i++);
       usleep(1000000);
    }
}

int main(int argc,char **argv){
    struct STU st[]={
        {10,12,"aaaa"},
        {20,23,"bbbb"}
    };

    pthread_t pid[2];
    int i;
    for(i=0;i<2;i++){
        pthread_create(&pid[i],NULL,run,&st[i]);
    }                                                 
    printf("%u,%u\n",pid[0],pid[1]);
    pthread_join(pid[0],NULL);
    pthread_join(pid[1],NULL);
    return 0;
}
