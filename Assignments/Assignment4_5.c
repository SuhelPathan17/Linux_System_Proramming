#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>


int main(int argc, char *argv[])
{
    int fd = 0;
    char Buffer[20];
    int ret = 0;

    if(argc !=3)
    {
        printf("Insufficint no. of arguments\n");
        return -1;
    }

    fd = open(argv[1],O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return-1;
    }

    lseek(fd,atoi(argv[2]),0);
    // fd = file , argv[2] = positon from which we want to start reading

    ret = read(fd,Buffer,20);

    printf("Data from file is :\n");
    write(1,Buffer,ret);

    close(fd);

    return 0;
}