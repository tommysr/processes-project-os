#include <stdio.h>
#include <sys/types.h>
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

void wait_all()
{
  int child_status, child_pid;

  for (int i = 0; i < 3; i++)
  {
    child_pid = wait(&child_status);

    if (child_pid == -1)
    {
      perror("waiting for child process error");
      exit(EXIT_FAILURE);
    }

    printf("child process PID: %d returned with status: %d\n", child_pid, child_status);
  }
}

int main()
{
  char pstree_cmd[20];
  int exec_status;
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
      exec_status = execl("./p1", "p1", NULL);

      if (exec_status == -1)
      {
        perror("execl error, cannot execute");
        exit(EXIT_FAILURE);
      }

      break;
    default:
      break;
    }
  }

  system(pstree_cmd);
  wait_all();

  return 0;
}
