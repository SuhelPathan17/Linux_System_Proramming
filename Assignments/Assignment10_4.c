#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void* ThreadProc(void *ptr)
{
    printf("Inside Thread\n");
    printf("Parameter from user to thread is : %d\n",(int)ptr);
    int iValue = (int)ptr;
    pthread_exit(++iValue);
}
int main()
{
    pthread_t TID;
    int iRet = 0;
    int iNo = 10;
    int value = 0;

    iRet = pthread_create(&TID,NULL,ThreadProc,(int*)iNo);
    if(iRet != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }
    
    printf("Thread is created with Pid %d\n",TID);
    pthread_join(TID,&value);

    printf("return value from thread is : %d\n",value);

    printf("End of main Thread\n");
    return 0;
}