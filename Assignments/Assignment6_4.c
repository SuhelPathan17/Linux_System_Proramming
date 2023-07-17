#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    int fd = 0;
    int fd1 = 0;
    char Buffer[BLOCKSIZE];
    int ret = 0;
 
    char FileName[50];
    char FileDetails[50]; 

    struct stat sobj;

    if(argc != 2)
    {
        printf("Insuficient no. of arguments\n");
        return -1;
    }

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open dir\n");
        return -1;
    }
    

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(FileName,"%s/%s",argv[1],entry->d_name);
        stat(FileName,&sobj);
        if(S_ISREG(sobj.st_mode))
        {
            if(sobj.st_size > 600)
            {
                remove(FileName);
            } 
        }
    }

    closedir(dp);

    return 0;
}