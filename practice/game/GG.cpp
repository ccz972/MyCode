#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int pid1, pid2;
int main() {
  int fd[2];  // 打开文件的文件描述符
  char OutPipe[100], InPipe[100];
  // printf("HelloWorld!\n");
  pipe(fd);  // 创建管道
  while ((pid1 = fork()) == -1)
    ;                    // 创建子进程
  if (pid1 == 0) {       // 在子进程1中
    lockf(fd[1], 1, 0);  // 给文件上锁，以实现互斥访问
    sprintf(OutPipe, "Child 1 is sending a message!");  // 将字符串赋给InPipe
    //      printf("%s\n", InPipe);
    write(fd[1], OutPipe, 50);
    lockf(fd[1], 0, 0);  // 给文件解锁
    // printf("Child1 is end");
    sleep(1);  // 延时1秒
    exit(0);   // 子进程结束
  } else {
    while ((pid2 = fork()) == -1)
      ;  // 创建子进程
    if (pid2 == 0) {
      sleep(0);
      lockf(fd[1], 1, 0);
      sprintf(OutPipe, "Child 2 is sending a message!");
      write(fd[1], OutPipe, 50);  // 向管道中写入数据
      lockf(fd[1], 0, 0);         // 解锁
      sleep(1);                   // 延时1秒
      exit(0);                    // 子进程正常退出
    } else {
      wait(0);  // 等待子进程执行完毕
      wait(0);  // 等待子进程执行完毕

      read(fd[0], InPipe, 50);

      printf("%s\n", InPipe);

      read(fd[0], InPipe, 50);

      printf("%s\n", InPipe);

      exit(0);  // 父进程结束
    }
  }

  return 0;
}
