#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
    printf("Real User Id : %d\n",getuid());
    printf("Effective User Id : %d\n",geteuid());

    // execl("/bin/ls","ls","sample.txt", NULL);
    printf("this line wont exe if execl will\n  ");
    return 0;
}