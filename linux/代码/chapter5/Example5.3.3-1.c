#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
int main(int argc,char **argv){
    int fd=-1;
    fd=creat(argv[1],00777);
    if (fd<0){
         printf("errno: %s\n",strerror(errno));
    }
    else {
         printf("ok : %d\n",fd);
         close(fd);
    }
    return 0;
}
