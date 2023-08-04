#include<stdio.h>
#include<stdbool.h>
#include<fcntl.h>
#include "sharedfile.h"
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>

bool CompareFiles(char *str1, char *str2)
{
    int fd1 = 0;
    int fd2 = 0;
    int Buffer1[1024];
    int Buffer2[1024];
    int iRet = 0;
    struct stat obj1,obj2;

    fd1 = open(str1,O_RDONLY);
    fd2 = open(str2,O_RDONLY);

    if(fd1 == -1 || fd2 == -1)
    {
        printf("Unable to open the file\n");
        return false;
    }

    fstat(fd1,&obj1);
    fstat(fd2,&obj2);

    if(obj1.st_size != obj2.st_size)
    {
        printf("Files are of different sizes\n");
        return false;
    }

    while((iRet = read(fd1,Buffer1,sizeof(Buffer1))) != 0)
    {
        iRet = read(fd2,Buffer2,sizeof(Buffer2));
        if(memcmp(Buffer1,Buffer2,iRet) != 0)
        {
            break;
        }
        
    }

    if(iRet == 0)
    {
        close(fd1);
        close(fd2);
        return true;
    }
    else
    {
        close(fd1);
        close(fd2);
        return false;
    }
    

}

// To create .o file
// gcc -c -fPIC sharedfile.c

// To create .so file
// gcc -shared -o library.so sharedfile.o