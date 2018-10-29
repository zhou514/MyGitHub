 #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    static int (*sendstate)(int,int);
    static int state;  
    void* run(void* arg){
        int i=0;
        int size=180;
        while(state){
           while(state==2) usleep(20000);//Î¢Ãë
           sendstate(state,i++);
           if (i>=size) break;
           sleep(1);
        }
        state=0;
        sendstate(state,i++);
    }
int play(char *file,int (*handler)(int,int)){
        if (state==0){
           sendstate=handler;
           state=1;
           pthread_t id;
           pthread_create(&id,NULL,run,NULL);
        }
        else state=1;
    }
    int pause(){
        state=2;
        sendstate(state,0);
    }
    int stop(){
        state=0;
        sendstate(state,0);
    }
