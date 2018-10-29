#include <unistd.h>
#include <stdio.h>
main()
{
int filedes[2];
char buffer[80];
pipe(filedes);
if(fork()>0)
{
char s[ ] = "hello!\n";
write(filedes[1],s,sizeof(s));
}
else
{
read(filedes[0],buffer,80);
printf("%s",buffer);
}
}
