#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
void sigaction_handle(int signo,siginfo_t *info,void *none){
     printf("receive signal %d,addtional data is %d,%s\n",signo,info->si_pid,none);
}
int main(int argc,char **argv){
    struct sigaction act,oact;
    memset(&act,0x00,sizeof(struct sigaction));
    sigemptyset(&act.sa_mask);
    act.sa_sigaction = sigaction_handle;
    act.sa_flags = SA_SIGINFO;
    if(sigaction(SIGINT,&act,&oact) == -1){
        perror("sigaction");
        exit(0);
    }
pause();
return 0;
}
