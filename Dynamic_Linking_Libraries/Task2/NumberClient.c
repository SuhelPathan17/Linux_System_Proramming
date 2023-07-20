#include"NumbersSharedfile.h"
#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>



int main()
{
    void *ptr = NULL;
    int(*fptr)(int, int);
    int(*fptr1)(int);


    int iNo1 = 10;
    int iNo2 = 11;
    int iRet = 0;

    ptr = dlopen("/home/suhel/Desktop/LSP/My_Programs/dynamic/Numberslibrary.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load library\n");
        return -1;
    }

    fptr = dlsym(ptr,"Addition");
    if(fptr == NULL)
    {
        printf("Unable to load address of function\n");
        return -1;
    }

    iRet = fptr(iNo1,iNo2);
    printf("Addition is %d\n",iRet);

    fptr = dlsym(ptr,"Substraction");
    if(fptr == NULL)
    {
        printf("Unable to load address of function\n");
        return -1;
    }

    iRet = fptr(iNo1,iNo2);
    printf("Substraction is %d\n",iRet);

    fptr = dlsym(ptr,"Multiplication");
    if(fptr == NULL)
    {
        printf("Unable to load address of function\n");
        return -1;
    }

    iRet = fptr(iNo1,iNo2);
    printf("Multiplication is %d\n",iRet);

    fptr1 = dlsym(ptr,"Factorial");
    if(fptr1 == NULL)
    {
        printf("Unable to load address of function\n");
        return -1;
    }

    iRet = fptr1(iNo1);
    printf("Factorial is %d\n",iRet);

    
    return 0;
}   
