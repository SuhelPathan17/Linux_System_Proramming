#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>
#include<stdbool.h>

int main(int argc, char *argv[])
{
    void *ptr = NULL;
    bool (*fptr)(char *, char *);
    bool bRet = false;

    //Give Absolute Path
    ptr = dlopen("/home/suhel/Desktop/LSP/Assignments/Assignement7/Assignement7_2/library.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load library\n");
        return -1;
    }

    fptr = dlsym(ptr,"CompareFiles");
    if(fptr == NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }

    bRet = fptr(argv[1],argv[2]);
    if(bRet == true)
    {
        printf("Both files are identical\n");
    }
    else
    {
        printf("Both files are different\n");
    }
    return 0;
}

// gcc -rdynamic -o Myexe client.c
// gcc -ldl -o Myexe client.c

// ./Myexe
//$ usr/lib64/ld-linux-x86-64.so.2


