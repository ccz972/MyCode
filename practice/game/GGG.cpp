#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
  int x, fd[2];
  char buf[30], s[30];
  pipe(fd);
  while ((x = fork()) == -1)
    ;
  if (x == 0) {
    sprintf(buf, "this is an example\n");
    printf("child process running!\n");
    write(fd[1], buf, 30);
    sleep(5);
    exit(0);
  } else {
    wait(0);
    read(fd[0], s, 30);
    printf("%s", s);
  }
  return 0;
}
