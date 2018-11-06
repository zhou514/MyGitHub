//进程间通信， 客户端
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    int fd = open("/tmp/myfifo",O_WRONLY);
    if(fd == -1){
        printf("open error!\n");
        unlink("/tmp/myfifo");
        return 0;
    }
    char buf[256];
    while(1){
        scanf("%s",buf);
        int size = write(fd,buf,strlen(buf));
        printf("write size = %d,buf = %s\n",size,buf);
        if(strcmp(buf,"q") == 0) break;
    }
    close(fd);
}