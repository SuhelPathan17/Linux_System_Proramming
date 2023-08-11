#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void* ThreadProc(void *ptr)
{
    printf("Inside Thread\n");
    printf("Parameter to thread is : %d\n",(int)ptr);
}
int main()
{
    pthread_t TID;
    int iRet = 0;
    int iNo = 10;

    iRet = pthread_create(&TID,NULL,ThreadProc,(int*)iNo);
    if(iRet != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }
    
    printf("Thread is created with Pid %d\n",TID);
    pthread_join(TID,NULL);

    printf("End of main Thread\n");
    return 0;
}