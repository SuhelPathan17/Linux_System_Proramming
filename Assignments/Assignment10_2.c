#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void* ThreadProc1(void *ptr)
{
    printf("Inside Thread 1\n");
    int iCnt = 0;
    for(iCnt = 1; iCnt <= 500; iCnt++)
    {
        printf("%d\n",iCnt);
    }
}

void* ThreadProc2(void *ptr)
{
    printf("Inside Thread 2\n");
    int iCnt = 0;
    for(iCnt = 500; iCnt >= 1; iCnt--)
    {
        printf("%d\n",iCnt);
    }
}

int main()
{
    pthread_t TID1;
    pthread_t TID2;

    int iRet1 = 0;
    int iRet2 = 0;


    iRet1 = pthread_create(&TID1,NULL,ThreadProc1,NULL);
    if(iRet1 != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }
    
    printf("Thread1 is created with Pid %d\n",TID1);

    iRet2 = pthread_create(&TID2,NULL,ThreadProc2,NULL);
    if(iRet2 != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }
    
    printf("Thread2 is created with Pid %d\n",TID2);

    pthread_join(TID1,NULL);
    pthread_join(TID2,NULL);

    printf("End of main thread\n");
    
    return 0;
}