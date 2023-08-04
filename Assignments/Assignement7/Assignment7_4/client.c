#include"sharedfile.h"
#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>
#include<stdbool.h>



int main(int argc, char *argv[])
{
    void *ptr = NULL;
    int(*fptr)(int);
    
    int iNo = atoi(argv[1]);

    int iRet = 0;

    ptr = dlopen("/home/suhel/Desktop/LSP/Assignments/Assignement7/Assignment7_4/library.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load library\n");
        return -1;
    }

    fptr = dlsym(ptr,"LoadLibrary");
    if(fptr == NULL)
    {
        printf("Unable to load address of function\n");
        return -1;
    }

    iRet = fptr(iNo);
    if(iRet == -1)
    {
        printf("Some Error\n");
        return -1;
    }
    else
    {
        printf("Factorial of %d is : %d\n",iNo,iRet);
    }

    return 0;
}   
        

        