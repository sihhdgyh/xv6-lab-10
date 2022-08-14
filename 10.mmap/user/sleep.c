// Lab Xv6 and Unix utilities
// sleep.c

// 引入声明类型的头文件
#include "kernel/types.h"
// 引入头文件
#include "user/user.h"
#include "kernel/stat.h"

// int main(int argc,char* argv[])
// argc 是命令行总的参数个数  
// argv[] 是 argc 个参数，其中第 0 个参数是程序的全名，以后的参数是命令行后面跟的用户输入的参数
int main(int argc, char *argv[])
{
    // 如果命令行参数不等于2个，则打印错误信息
    if (argc != 2)
    {
        // 当然这里使用 user/printf.c 中的 fprintf(int fd, const char *fmt, ...) 函数进行格式化输出,2 表示标准错误
        fprintf(2, "Usage: sleep seconds\n");
        // 退出程序
        exit(1);
    }
    // 把字符串型参数转换为整型
    int time = atoi(argv[1]);
    // 调用系统调用 sleep 函数，传入整型参数
    sleep(time);
    // 正常退出程序
    exit(0);
}
