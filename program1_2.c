#include <stdio.h>
#include <sys/types.h>
#include <sys/errno.h>
#include <unistd.h>
#include <stdlib.h>

void print_process_info(){
  printf("PID: %d\n", (int)getpid());
  printf("PPID: %d\n", (int)getppid());
  printf("UID: %d\n", (int)getuid());
  printf("GID: %d\n", (int)getgid()); 
}

int main(){
 char pstree_cmd[20];
 int parent_pid = (int)getpid();
 sprintf(pstree_cmd, "pstree -ph %d", parent_pid);
 printf("Parent:\n");
 print_process_info();

 for(int i = 0; i < 3; i++) {
   switch(fork()){
     case -1:
       perror("fork error, cannot create child process");
       exit(1);
       break;
     case 0:
       printf("child %d\n", i);
       print_process_info();
       break;
     default:
       printf("fork");
       sleep(1);
   } 
 }
 
 system(pstree_cmd);

 return 0;
}
