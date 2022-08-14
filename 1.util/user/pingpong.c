// Lab Xv6 and Unix utilities
// pingpong.c
#include "kernel/types.h"
#include "user/user.h"
#include "stddef.h"
//所需头文件
int
main(int argc, char *argv[])
{
int ptoc_fd[2], ctop_fd[2];
//两个数组用于进程之间信息的传递
    pipe(ptoc_fd);
pipe(ctop_fd);
//创建两个管道
char buf[8];
//缓冲区字符数组buf，用于存放父进程与子进程之间传递的信息
    if (fork() == 0) {
        //为子进程
        read(ptoc_fd[0], buf, 4);
//读取父进程传来的信息
        printf("%d: received %s\n", getpid(), buf);
//输出相关信息
        write(ctop_fd[1], "pong", strlen("pong"));
//写入要传给父进程的信息
    }
    else {
        //父进程
        write(ptoc_fd[1], "ping", strlen("ping"));
//写入要传给子进程的信息
        wait(NULL);
//等待子进程执行完
        read(ctop_fd[0], buf, 4);
//读取子进程传来的信息
        printf("%d: received %s\n", getpid(), buf);
//输出相关信息
    }
    exit(0);
}
