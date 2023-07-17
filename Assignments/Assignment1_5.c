#include<stdio.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    int Ret = 0;
    char Buffer[20] = {'\0'};

    if(argc != 3)
    {
        printf("Invalid number of arguments\n");
        return -1;
    }

    fd = open(argv[1], O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }
    else
    {
        printf("File is succesfully opened with fd : %d\n",fd);
    }

    Ret = read(fd,Buffer,atoi(argv[2]));
    if(Ret == 0)
    {
        printf("Unable to read data from file file\n");
        return -1;
    }
    else
    {
        printf("Data from File is : %s\n",Buffer);
    }

    return 0;
}