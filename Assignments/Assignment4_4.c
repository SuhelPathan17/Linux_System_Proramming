#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>


int main(int argc, char *argv[])
{
    char DirName[20];
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char name[30];
    struct stat sobj;
    char Buffer[10];
    int fd1 = 0;
    int fd2 = 0;
    int Ret =0;


    if(argc != 2)
    {
        printf("Insufficient no. of arguments\n");
        return -1;
    }

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    fd1 = creat("Demo.txt",0777);
    if(fd1 == -1)
    {
        printf("Unable to create file\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(name,"%s/%s",argv[1],entry->d_name);
        stat(name,&sobj);

        if(S_ISREG(sobj.st_mode))
        {
            fd2 = open(name,O_RDWR);
            Ret = read(fd2,Buffer,10);
            write(fd1,Buffer,Ret);
        }
        else
        {
            printf("Not a Reg File\n");
        }
        Ret = 0;
    }

    closedir(dp);
    
    return 0;
}