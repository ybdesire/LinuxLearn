#include <stdio.h>
#include <unistd.h>//access POSIX API

int main(int argc, char **argv)
{
    pid_t pid;
    int count = 0;
    printf("let's fork\n");
    pid = fork();
    if(pid<0)//error
    {
        printf("fork error\n");
    }
    else if(pid==0)
    {
        printf("child process, pid: %d, count=%d\n", getpid(), ++count);
    }
    else
    {
	printf("parent process, pid: %d, count=%d\n", getpid(), ++count);
    }
    return 0;
}
