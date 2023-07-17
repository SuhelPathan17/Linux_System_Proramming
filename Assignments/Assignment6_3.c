#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char FileName[30];
    int fd = 0;


    if(argc != 3)
    {
        printf("Insuficient no. of arguments\n");
        return -1;
    }

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open dir \n");
        return -1;
    }

    sprintf(FileName,"%s/%s",argv[1],argv[2]);

    fd = creat(FileName,0777);
    if(fd == -1)
    {
        printf("Unable to create file \n");
        closedir(dp);
        return -1;
    }

    closedir(dp);

    return 0;
}