#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#include<dirent.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    DIR *dp1 = NULL;
    DIR *dp2 = NULL;

    struct dirent *entry1 = NULL;
    struct dirent *entry2 = NULL;

    char name1[257];
    char name2[257];

    int fd1 = 0;
    int fd2 = 0;

    char Buffer[BLOCKSIZE];
    int Ret = 0;

    if(argc != 3)
    {
        printf("Insufficient no. of arguments\n");
        return -1;
    }

    dp1 = opendir(argv[1]);
    if(dp1 == NULL)
    {
        printf("Unable to create directory\n");
        return -1;
    }

    dp2 = opendir(argv[2]);
    if(dp2 == NULL)
    {
        printf("Unable to create directory\n");
        return -1;
    }

    struct stat sobj;

    while((entry1 = readdir(dp1)) != NULL)
    {   
        sprintf(name1,"%s/%s",argv[1],entry1->d_name);
        stat(name1,&sobj);
        if(S_ISREG(sobj.st_mode))
        {
            
            fd1 = open(name1,O_RDWR);
            if(fd1 == -1)
            {
                printf("Unable to open file\n");
                closedir(dp1);
                closedir(dp2);
                return -1;
            }

            
        
            sprintf(name2,"%s/%s",argv[2],entry1->d_name);

            fd2 = creat(name2,0777);
            if(fd2 == -1)
            {
                printf("Unable to create file\n");
                return -1;
            }

            while((Ret = read(fd1,Buffer,sizeof(Buffer)) ) != 0)
            { 
                write(fd2,Buffer,Ret);
            }
        }
        else
        {
            printf("Not a Reg File\n");
        }
        
    }

    closedir(dp1);
    closedir(dp2);

    return 0;
}