#include <stdio.h>
#include <sys/types.h>
#include <sys/errno.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

void print_process_info()
{
  printf("\nPID: %d\n", getpid());
  printf("PPID: %d\n", getppid());
  printf("UID: %d\n", getuid());
  printf("GID: %d\n", getgid());
}

int main()
{
  char pstree_cmd[20];
  sprintf(pstree_cmd, "pstree -p %d", getpid());
  // print_process_info();

  for (int i = 0; i < 3; i++)
  {
    switch (fork())
    {
    case -1:
      perror("fork error, cannot create child process");
      exit(EXIT_FAILURE);
    case 0:
      print_process_info();
      break;
    default:
      // sleep(1);
      break;
    }
  }

  sleep(1);
  system(pstree_cmd);

  return 0;
}
