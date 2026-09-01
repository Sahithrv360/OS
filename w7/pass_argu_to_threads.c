#include<stdio.h>
#include<pthread.h>

void *thread_function(void *arg){
    int number = *(int *)arg;

    printf("Thread %d is exe...\n",number);
    for(int i = 1;i <= 5;i++){
        printf("Thread : %d \n",i);
    }

    printf("\nThread Execution has comleted ...\n");
    return NULL;
}

int main(){
    int n1 = 1,n2 = 2;
    pthread_t t1,t2;

    pthread_create(&t1,NULL,thread_function,&n1);
    pthread_create(&t2,NULL,thread_function,&n2);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    printf("Both threads have completed.\n");

    return 0;

}