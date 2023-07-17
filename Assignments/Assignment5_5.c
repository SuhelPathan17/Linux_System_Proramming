#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>

#define BLOCKSIZE 1024


int main(int argc, char *argv[])
{
    int fd = 0;
    int fdNew = 0;
    char Buffer[BLOCKSIZE];
    char FileName[20];
    int iCnt = 0;
    int ret = 0;

    open(argv[1],O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to create file\n");
        return -1;
    }

    while((ret = read(fd,Buffer,sizeof(Buffer))) != 0)
    {
        printf("%c",Buffer[0]);
        while(iCnt < ret)
        {
            if(Buffer[iCnt] == " ")
            {
                break;
            }
            else
            {
                strcpy(Buffer[iCnt],FileName[iCnt]);
            }
        }

        fdNew = creat(FileName,0777);
        if(fdNew == -1)
        {
            printf("Unable to create file\n");
            return -1;
        }
        iCnt++;
    }

    return 0;
}