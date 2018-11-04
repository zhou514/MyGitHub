使用creat函数创建一个文件，当没有文件名输入时，提示用户输入一个文件名。
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
void  create_file(char *filename)
{ 
    /*创建的文件具有可读可写的属性*/	
    if(creat(filename,0666)<0)
	{ 
        printf("create file %s failure!\n",filename); 
        exit(EXIT_FAILURE); 
    }
	else
	{ 
        printf("create file %s success!\n",filename); 
    } 
} 
int main(int argc,char *argv[])
{ 
    /*判断入参有没有传入文件名 */
   	if(argc<2)
	{ 
        printf("you haven't input the filename,please try again!\n"); 
        exit(EXIT_FAILURE); 
    }
	create_file(argv[1]);
	exit(EXIT_SUCCESS);}
