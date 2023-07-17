#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

#define BLOCKSIZE 1024
int main(int argc, char *argv[])
{
    int fd = 0;
    char Buffer[BLOCKSIZE];
    int Ret = 0;

    if(argc != 2)
    {
        printf("Insufficient no. of arguments\n");
        return -1;
    }


    fd = open(argv[1],O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open the file \n");
        return -1;
    }
    else
    {
        printf("File is successfully opened with fd %d\n",fd);
    }

    while((Ret = read(fd,Buffer,sizeof(Buffer))) != 0)
    {
        write(1,Buffer,Ret);  
    }

    close(fd);

    return 0;
}