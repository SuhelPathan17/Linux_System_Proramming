#include<stdio.h>
#include<sys/resource.h>

int main()
{
    int iRet = 0;

    iRet = getpriority(PRIO_PROCESS,0); //A zero value for who denotes (respectively) the calling process,

    printf("Priority of current process is %d\n",iRet);

    return 0;
}