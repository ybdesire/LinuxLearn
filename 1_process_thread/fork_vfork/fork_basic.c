#include <stdio.h>
#include <unistd.h>//access POSIX API

int main(int argc, char **argv)
{
    pid_t pid;
    printf("let's fork\n");
    pid = fork();
    if(pid<0)//error
    {
        printf("fork error\n");
    }
    else if(pid==0)
    {
        printf("child process, pid: %d\n", getpid());
    }
    else
    {
	printf("parent process, pid: %d\n", getpid());
    }
    return 0;
}
