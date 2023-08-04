#include"sharedfile.h"
#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>
#include<stdbool.h>



int main(int argc, char *argv[])
{
    void *ptr = NULL;
    bool(*fptr)(int);
    
    int iNo = atoi(argv[1]);

    bool bRet = false;

    ptr = dlopen("/home/suhel/Desktop/LSP/Assignments/Assignement7/Assignement7_3/library1.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load library\n");
        return -1;
    }

    fptr = dlsym(ptr,"CheckPrime");
    if(fptr == NULL)
    {
        printf("Unable to load address of function\n");
        return -1;
    }

    bRet = fptr(iNo);
    if(bRet == true)
    {
        printf("%d is prime number\n",iNo);
    }
    else
    {
        printf("%d is not a prime number\n",iNo);
    }


    ptr = dlopen("/home/suhel/Desktop/LSP/Assignments/Assignement7/Assignement7_3/library2.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load library\n");
        return -1;
    }

    fptr = dlsym(ptr,"CheckPerfect");
    if(fptr == NULL)
    {
        printf("Unable to load address of function\n");
        return -1;
    }

    bRet = fptr(iNo);
    if(bRet == true)
    {
        printf("%d is Perfect number\n",iNo);
    }
    else
    {
        printf("%d is not a Perfect number\n",iNo);
    }

    return 0;
}   
        

        