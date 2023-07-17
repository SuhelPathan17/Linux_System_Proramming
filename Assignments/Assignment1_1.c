#include<stdio.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
    char Fname[10];
    int fd = 0;

    printf("Please Enter the file name you want to open : \n");
    scanf("%s",Fname);

    fd = open(Fname,O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open the file \n");
    }
    else
    {
        printf("File is successfully opened with fd %d\n",fd);
    }


    return 0;
}