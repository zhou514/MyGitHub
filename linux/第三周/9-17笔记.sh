Linux编程基础
1.编辑器
    功能分类：行编辑器/全屏编辑器（vi） 
    vi编辑器：命令‘行模式/插入模式/底行模式
    （1）命令行模式：可以查看文件内容，但是不能编辑文字；上下移动光标，删除字符或删除整行
    （2）插入模式：进行文字编辑输入；用户可以通过ESC键回到命令模式
    （3）底行模式：光标位于编辑器底行；对文件保存或退出

    常用命令
    （1）命令行常用命令
    i/a/o 
    ctrl+b  ctrl+f  前后翻一页      /  翻半页 ctrl+u ctrl+d
    x 删除当前字符  dd 删除当前行    eg：2x    2dd
    u 恢复前一个动作（撤销）
    （2）底行常用命令
    ：w 保存
    ：q 退出vi编辑器
    ：q！强制退出
    ：wq
    ：w [filename]  另存为名为filename的文件
    ：set nu 显示行号
    ：set nonu 不显示行号

程序编译gcc
gcc 参数 源文件
.c  C源程序
.C/cc/.cxx  C++源程序
.m  Objective-C 
.i 经过预处理的C源程序
.ii C++
.s/.S 汇编语言源程序
.h 预处理文件（头文件）
.o 目标文件
.a/.so 编译后的库文件

gcc编译流程：预处理->编译->汇编->链接
                        -E         -S          -c

参数：
-c 只编译不链接
-S 只编译不汇编
-E 只进行预处理
-o file 将文件输出到file里
-g 在可执行程序中包含标准调式信息
-v 打印
-static 链接静态库
-l library 链接文件名为library的库文件


C语言进阶
数据类型
auto 声明自动变量  a = 0;
int 4个字节
double
long
char
float
short
signed声明有符号类型变量
unsigned 无符号
struct结构体变量
union 联合数据变量
enum 枚举类型
static 静态
switch case default break
register 寄存器变量
const 只读变量
volatile 变量在程序中可被隐含地改变
typedef 用于给数据类型取别名
    typedef struct Hello{
        int a;
        int b;
    }A;

常量
#define PI 3.1415926
变量
int  a = 1;  a = 3;

转义字符
'\'' 单引号
'\''' 双引号
'\t' tab
'\b' 退格键
'\a' 警铃
'\r' 回车
'\n' 换行
'\ddd' 八进制
'\xhh' 十六进制