#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

void print_process_info()
{
  printf("PID: %d\n", getpid());
  printf("PPID: %d\n", getppid());
  printf("UID: %d\n", getuid());
  printf("GID: %d\n", getgid());
}

int main()
{
  print_process_info();
  return 0;
}
