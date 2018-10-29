类型转换
1.自动类型转换
	char short int long float double
	'c' + 2 
	#int 
	23f + 12 #float
	'a' + 'b' #int 
	'c' + 32 + (4e + 1) # double
	int a = 2.2; #a = 2
	double b = 2; #b = 2.0
2.强制转换
	格式：(类型) 值
	(int) 3/2
	(double) 3/2 #3.0/2.0 = 1.5
	int a = 1; (double) a;
	int *p = &a; char *str = (char *) p;

3.字符串与数值之间的转换
	<string.h>
	int atoi(const char *nptr)
	long atol(const char *nptr)
	
#include<stdio.h>

int main(int argc, char **argv){
	//字符串转换整型
	int a = atoi(argv[1]);
	printf("%d\n",a);
	int b = atoi("8");
	printf("%d\n",b);
	//字符转换整型
	int c = '8' - '0';
	printf("%d\n",c);
	return 0;
}

#include<stdio.h>

int main(int argc ,char ***argv){
    int a = 23;
    char str[256];
    sprintf(str,"%d",a); //将一个整型转换成字符串
    printf("%s\n",str);
    return 0;
}