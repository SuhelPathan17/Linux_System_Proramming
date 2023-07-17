#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    struct stat sobj;

    if(argc != 2)
    {
        printf("Insufficient no. of arguments\n");
        return -1;
    }

    stat(argv[1],&sobj);

    printf("Name of File : %s\n",argv[1]);
    printf("File Size is : %d\n",sobj.st_size);
    printf("No. of Links : %d\n",sobj.st_nlink);
    printf("Inode No. : %d\n",sobj.st_ino);
    printf("FileSystem number : %d\n",sobj.st_dev);
    printf("Number of blocks : %d\n",sobj.st_blocks);


    return 0;
}