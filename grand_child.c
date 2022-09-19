#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char** argv)
{
    pid_t child_pid;
    child_pid = fork();
    if (child_pid == 0)
    {
        pid_t grand_child_pid;
        grand_child_pid = fork();
        printf("This is process %d\n", getpid());
        
        if(grand_child_pid == 0) {
          execlp("/usr/bin/firefox", "firefox", NULL);
      }
    }
    printf("This is process %d\n", getpid());
    wait(NULL);
    return 0;
}
