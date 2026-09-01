#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
	pid_t child_pid;
	child_pid = fork();  // creates a child process
	if (child_pid == 0) {
	    printf("Child Process\n");
	    printf("Child PID : %d\nParent PID : %d\n",getpid(), getppid());
	} else {
	    wait(NULL);
	    printf("Parent Process\n");
	    printf("Parent PID : %d\nGrandparent PID : %d\n",getpid(), getppid());
	}
	return 0;
}
