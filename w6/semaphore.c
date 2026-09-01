#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>

int shared = 1;
sem_t sem;

void *thread1(void *arg){
    sem_wait(&sem);
    shared++;
    printf("Thread 1: shared = %d\n", shared);
    sem_post(&sem);
    return NULL;
}

void *thread2(void *arg){
    sem_wait(&sem);
    shared--;
    printf("Thread 2: shared = %d\n", shared);
    sem_post(&sem);
    return NULL;
}

int main(){
    pthread_t t1,t2;
    sem_init(&sem,0,1);

    pthread_create(&t1, NULL, thread1, NULL);
    pthread_create(&t2, NULL, thread2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final value = %d\n", shared);

    sem_destroy(&sem);
    return 0;
}