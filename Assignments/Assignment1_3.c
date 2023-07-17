#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    int Mode = 0;
    //char Fname[20] = {'\0'};

    if(argc != 3)
    {
        printf("Invalid number of arguments\n");
        return -1;
    }

    //strcpy(Fname,argv[1]);
    //printf("%s\n",Fname);

    if(strcmp(argv[2],"Read") == 0)
    {
        Mode = O_RDONLY;
    }
    else if(strcmp(argv[2],"Write") == 0)
    {
        Mode = O_WRONLY;
    }
    else
    {
        Mode = O_RDONLY;
    }

    fd = access(argv[1],Mode);
    if(fd == -1)
    {
        printf("process cannot access this file \n");
    }
    else
    {
        printf("process access this file \n");
    }

    return 0;
}
