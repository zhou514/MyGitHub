#include <stdio.h> 
#include <string.h> 
int main(int argc,char **argv){   
    int w;
    scanf("%d",&w);
    char*  str;
    switch((0+w)%7){
    case 0: str="日"; break;//字符串本身就是地址，地址存在了str变量中
    case 1:  str="一"; break;
    case 2:  str="二"; break;
    case 3:  str="三"; break;
    case 4:  str="四"; break;
    case 5:  str="五"; break;
    case 6:  str="六"; break;
    }
    printf("---今在是周%s\n",str);
}
