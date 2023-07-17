#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

#define BLOCKSIZE 1024
int main(int argc, char *argv[])
{
    int fd = 0;
    int Ret = 0;
    char str[10] = "Hi Suhel";

    if(argc != 2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    fd = open(argv[1],O_WRONLY);
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }
    
    Ret = write(fd,str,strlen(str));
    if(Ret == -1)
    {
        printf("Unable to write in file\n");
        return -1;
    }
    else
    {
        printf("Successfully written %d bytes of dat into file \n",Ret);
    }
    return 0;
}