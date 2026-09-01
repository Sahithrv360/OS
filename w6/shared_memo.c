#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/wait.h>

int main()
{
    int shmid;
    char *memory;
    char msg[] = "Hello from Parent";

    shmid = shmget(IPC_PRIVATE, 1024, 0666 | IPC_CREAT);

    if (fork() == 0)
    {
        sleep(1);

        memory = shmat(shmid, NULL, 0);

        printf("Child received: %s\n", memory);

        shmdt(memory);
    }
    else
    {
        memory = shmat(shmid, NULL, 0);

        strcpy(memory, msg);

        shmdt(memory);

        wait(NULL);

        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}