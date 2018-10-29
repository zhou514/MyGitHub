int main(){
      int a=12; //局部变量
      int* p=&a; //给p赋值，而不是给*p赋值
	  printf("%d",*p);
    }
