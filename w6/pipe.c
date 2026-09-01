#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>

int main(){
    int pipefd[2];
    pid_t pid;

    char write_msg[] = "Welcome to world!!! Child Process";
    char read_msg[100];
    
    if(pipe(pipefd) == -1){
        perror("pipe"); 
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if(pid == -1){
        perror("fork"); 
        exit(EXIT_FAILURE);
    }

    if(pid > 0){
        printf("Parent process : sending message to child...\n");
        close(pipefd[0]);

        write(pipefd[1],write_msg,strlen(write_msg)+1);

        printf("Parent process : message sent to successfully...\n");
        
        close(pipefd[1]);

        wait(NULL);
        printf("Process: Child process completed.\n");
    }else{
        close(pipefd[1]);

        read(pipefd[0],read_msg,sizeof(read_msg));
        printf("Child Process: Message received: %s\n", read_msg);
        close(pipefd[0]);
        exit(0);
    }
    return 0;
}