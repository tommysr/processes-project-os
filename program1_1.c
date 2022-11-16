#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
  printf("PID: %d \n", (int)getpid());
  printf("PPID: %d \n", (int)getppid());
  printf("UID: %d \n", (int)getuid());
  printf("GID: %d \n", (int)getgid());

  return 0;
}
