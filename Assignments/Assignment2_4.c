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
    char Mode[20];

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

        if(S_ISREG(sobj.st_mode))  // st_mode holds filetype
        {
            strcpy(Mode,"Regular");
        }
        else if(S_ISDIR(sobj.st_mode)) 
        {
            strcpy(Mode,"Directory");
        }
        else if(S_ISLNK(sobj.st_mode))
        {
            strcpy(Mode,"SymbolicLink");
        }


        printf("File Name : %s\t File Type :%s\n",name,Mode);
    }

    closedir(dp);

    return 0;
}