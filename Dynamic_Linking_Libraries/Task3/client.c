#include"sharedfile.h"
#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>



int main()
{
    void *ptr = NULL;
    void *ptr1 = NULL;

    int(*fptr)(int, int);


    int iNo1 = 10;
    int iNo2 = 11;

    int iRet = 0;

    ptr = dlopen("/home/suhel/Desktop/LSP/My_Programs/dynamic/Task3/library1.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load library\n");
        return -1;
    }

    fptr = dlsym(ptr,"Loadlibrary");
    if(fptr == NULL)
    {
        printf("Unable to load address of function\n");
        return -1;
    }

    iRet = fptr(iNo1,iNo2);
    printf("Addition is : %d",iRet);
    return 0;
}   
        

        