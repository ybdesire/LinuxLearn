#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM 5


void *print_hello(void *arr)
{
    printf("hello, it's thread, %d\n", *(int*)arr);
    pthread_exit(NULL);//pthread_exit is the same as return
}


int main()
{
    pthread_t tid_arr[NUM];
    int rc, i;

    int * arr = (int *)malloc(sizeof(int));//arguments should be passed by heap
    *arr = 8;

    for(i=0;i<NUM;i++)
    {
        rc = pthread_create(&tid_arr[i], NULL, print_hello, (void *)arr);
    }

    free(arr);
    return 0;
}
