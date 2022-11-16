#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

void wait_all() {
  int child_status;
  int child_pid;

  for(int i=0; i<3; i++){
    child_pid = wait(&child_status);

    if (child_pid == -1)
    {
      perror("waiting for child process error");
      exit(1);
    }

    printf("child process PID: %d returned with status code: %d\n", child_pid, child_status); 
  }
}	


int main(){
 char pstree_cmd[20];
 int exec_status;
 sprintf(pstree_cmd, "pstree -p %d", (int)getpid());

 for(int i = 0; i < 3; i++) {
   switch(fork()){
     case -1:
       perror("fork error, cannot create child process");
       exit(1);
       break;
     case 0:
       printf("\nfork no.%d", i);
       exec_status = execl("./p1", "p1", NULL);

       if(exec_status == -1){
         perror("execl invoke error");
	 exit(1);
       }

       break;
     default:
       sleep(1);
   } 
 }
 
 system(pstree_cmd);
 wait_all();
 return 0;
}
