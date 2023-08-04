#include "sharedfile.h"
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>

void FileInfo(char *str)
{
    int fd = 0;
    struct stat sobj;

    fd = open(str,O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open the file\n");
        return -1;
    }

    fstat(fd,&sobj);

    printf("Inode no. %d\n",sobj.st_ino);
    printf("Device Id. %d\n",sobj.st_dev);
    printf("no. of hardlinks %d\n",sobj.st_nlink);
    printf("Size of file. %d\n",sobj.st_size);

}
