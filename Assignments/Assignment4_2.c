#include<stdio.h>

int main(int argc, char *argv[])
{
    int Ret = 0;

    if(argc != 2)
    {
        printf("Insufficient no. of arguments\n");
        return -1;
    }

    Ret = mkdir(argv[1],0777);
    if(Ret == -1)
    {
        printf("Unable to create directory\n");
        return -1;
    }

    return 0;
}