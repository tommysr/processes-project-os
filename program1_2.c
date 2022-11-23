#include <stdio.h>
#include <sys/types.h>
#include <sys/errno.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

// [20950] [22788] i=0 fork_id=22789  // MAIN
// [22788] [22789] i=0 fork_id=0

// [22788] [22789] i=1 fork_id=22791
// [22789] [22791] i=1 fork_id=0

// [22789] [22791] i=2 fork_id=22795
// [22791] [22795] i=2 fork_id=0

// [22788] [22789] i=2 fork_id=22793
// [22789] [22793] i=2 fork_id=0

// [20950] [22788] i=1 fork_id=22790 // MAIN
// [22788] [22790] i=1 fork_id=0

// [22788] [22790] i=2 fork_id=22794
// [22790] [22794] i=2 fork_id=0

// [20950] [22788] i=2 fork_id=22792 // MAIN
// [22788] [22792] i=2 fork_id=0

// OUT [20950] [22788]
// OUT [22788] [22789]
// OUT [22788] [22792]
// OUT [22788] [22790]
// OUT [22789] [22791]
// OUT [22791] [22795]

// OUT [1] [22793]
// OUT [1] [22794]

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
