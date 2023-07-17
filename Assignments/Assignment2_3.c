#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;

    if(argc != 2)
    {
        printf("insufficient no. of arguments\n");
        return -1;
    }

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("unable to open directory\n");
        return -1;
    }

    printf("----------------------------------------------------------\n");
    printf("Entries from the directory file are : \n");
    printf("----------------------------------------------------------\n");
    printf("|\tFile Name\t|\n");
    printf("----------------------------------------------------------\n");

    while((entry = readdir(dp)) != NULL)
    {
        printf("|\t%s\n",(entry->d_name));
    }

    return 0;
}