#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
    int fd1,fd2,num;
    fd1 = open("sample.txt",O_RDONLY | O_CREAT,0644);
    fd2 = open("f2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if(fd1 == -1 || fd2 == -1){
        printf("Files cant be opened");
        return 1;
    }
    printf("File descriptor of sample.txt : %d",fd1);
    printf("File descriptor of f2.txt : %d",fd2);

    printf("\nCurrent Process ID (PID) = %d\n", getpid());
    printf("ls /proc/%d\n", getpid());

    printf("Press any integer...");
    scanf("%d",&num);

}