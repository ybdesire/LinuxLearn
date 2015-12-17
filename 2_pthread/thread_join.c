#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM 5


void *print_hello()
{
    printf("hello, it's created thread, %ld\n", pthread_self());
    pthread_exit(NULL);//pthread_exit is the same as return
}


int main()
{
    pthread_t tid_arr[NUM];
    int rc, i;
    void *stat;

    for(i=0;i<NUM;i++)
    {
        rc = pthread_create(&tid_arr[i], NULL, print_hello, NULL);
        printf("main thread blocked here, waitting %ld\n", tid_arr[i]);
        pthread_join(tid_arr[i], stat);
    }

    return 0;
}
