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
 
    char s[] = "FileName";
    char d[] = "InodeNumber";
    char DataHeader[] = "Data From File is :";

    char FileName[50];
    char FileHeader[50];
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

    fd = creat("Data.txt",0777);
    if(fd == -1)
    {
        printf("Unable to create file\n");
        closedir(dp);
        return -1;
    }
    
    sprintf(FileHeader,"%s\t%s",s,d);
    write(fd,FileHeader,strlen(FileHeader));

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(FileName,"%s/%s",argv[1],entry->d_name);
        stat(FileName,&sobj);
        if(S_ISREG(sobj.st_mode))
        {
            sprintf(FileDetails,"\n%s\t%d\n%s\n",entry->d_name,entry->d_ino,DataHeader);
            write(fd,FileDetails,strlen(FileDetails));
            
            fd1 = open(FileName,O_RDONLY);

            ret = read(fd1,Buffer,sizeof(Buffer));
            write(fd,Buffer,ret);
        }
    }

    closedir(dp);

    return 0;
}