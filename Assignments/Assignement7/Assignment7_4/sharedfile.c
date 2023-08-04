#include"sharedfile.h"
#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>



int LoadLibrary(int iNo)
{
    void *ptr = NULL;
    int (*fptr)(int);
    int iRet = 0;

    ptr = dlopen("/home/suhel/Desktop/LSP/Assignments/Assignement7/Assignment7_4/Inner.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load library \n");
        return -1;
    }   

    fptr = dlsym(ptr,"Factorial");
    if(fptr == NULL)
    {
        printf("Unable to load address of func\n");
        return -1;
    }

    iRet = fptr(iNo);

    return iRet;
}