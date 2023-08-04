// InnerChild
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    printf("Inner Child process running with pid : %d\n",getpid());

    return 0;
}

