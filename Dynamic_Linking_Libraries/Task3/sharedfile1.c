#include"sharedfile.h"
#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>



int Loadlibrary(int iNo1, int iNo2)
{
    void *ptr = NULL;
    int(*fptr)(int, int);
    int iRet = 0;

    ptr = dlopen("/home/suhel/Desktop/LSP/My_Programs/dynamic/Task3/library.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load library \n");
        return -1;
    }

    fptr = dlsym(ptr,"Addition");
    if(fptr == NULL)
    {
        printf("Unable to load address of func\n");
        return -1;
    }
    
    iRet = fptr(iNo1,iNo2);
    return iRet;

    
}    

    

    
