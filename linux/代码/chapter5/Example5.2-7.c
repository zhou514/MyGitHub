#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

void print(int isls,char *name,char *dir){
  if (!isls){
     printf("%-15s\t",name);
  }
  else{
     struct stat st;
     char filename[256];
     sprintf(filename,"%s/%s",dir，name);
     stat(filename,&st);
     char type=' ';
     if (st.st_mode &S_IFDIR) type='d';
     else if (st.st_mode &S_IFREG) type='-';
     else if (st.st_mode &S_IFLNK) type='l';
     else if (st.st_mode &S_IFCHR) type='c';
     else if (st.st_mode &S_IFBLK) type='b';
     else if (st.st_mode &S_IFIFO) type='p';
     else if (st.st_mode &S_IFSOCK) type='s';
     char mod[10]="---------";
     if (st.st_mode &S_IRUSR) mod[0]='r';
     if (st.st_mode &S_IWUSR) mod[1]='w';
     if (st.st_mode &S_IXUSR) mod[2]='x';
     if (st.st_mode &S_IRGRP) mod[3]='r';
     if (st.st_mode &S_IWGRP) mod[4]='w';
     if (st.st_mode &S_IXGRP) mod[5]='x';
     if (st.st_mode &S_IROTH) mod[6]='r';
     if (st.st_mode &S_IWOTH) mod[7]='w';
     if (st.st_mode &S_IXOTH) mod[8]='x';
     int n=st.st_nlink;
     printf("%c%s %d %s\n",type,mod,n,name);
  }
}

int main(int argc,char **argv){
   int i，isls=0,isview=0;
   //     0        0       0 1目录  2文件
   char *dir="./",*file;
   for(i=1;argv[i]！=NULL;i++){
     if (argv[i][0]=='-'){
        if (argv[i][1]=='\0') continue;
        if (strchr(argv[i],'a')) isview=1;
        if (strchr(argv[i],'l')) isls=1;
     }
     else {
        char *p1=argv[1],*p=NULL;
        while((p=strstr(p1+1,"/"))！=NULL) p1=p;
        *p1=0;
        dir=argv[i];
     }
   }
   //--------------------------------------
   DIR *fp=opendir(dir);
   if (fp==NULL) return -1;
   struct dirent* db;
   while((db=readdir(fp))！=NULL){
      if (isview==0 && db->d_name[0]=='.') continue;
      print(isls,db->d_name,dir);
   }
   printf("\n");
   closedir(fp);
}

