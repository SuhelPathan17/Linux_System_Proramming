//ChildProcess
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int Ret = 0;
    int cpid = 0;
    int Exit_status = 0;

    Ret = fork();

    if(Ret == 0)  // Child  
    {
        execl("./InnerChild","NULL",NULL);
    }
    else        // Parent
    {
        printf("Child is running with PID : %d\n",getpid());
        cpid = wait(&Exit_status);
        printf("InnerChild process terminated having PID %d with exit status %d\n",cpid,Exit_status);
    }

    return 0;
}

