#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>
#include<string.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char name[30];

    if(argc != 3)
    {
        printf("Insuffiient no. of arguments\n");
        return -1;
    }

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to opem dir\n");
        return -1;
    }
    
    while((entry = readdir(dp)) != NULL)
    {
        if(strcmp(argv[2],entry->d_name) == 0)
        {
            break;
        }
    }

    if(entry== NULL)
    {
        printf("File is not present in directory\n");
    }
    else
    {
        printf("File is present in directory\n");

    }

    

    closedir(dp);

    return 0;
}