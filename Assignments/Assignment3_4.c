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
    int ret = 0;

    if(argc != 2)
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

    struct stat sobj;
    
    while((entry = readdir(dp)) != NULL)
    {
        sprintf(name,"%s/%s",argv[1],entry->d_name);
        stat(name,&sobj);

        if(sobj.st_size == 0)
        {
            ret = remove(name);
            if(ret == 0)
            {
                printf("%s File removed sucessfully\n",name);
            }
        }
    }

    closedir(dp);

    return 0;
}