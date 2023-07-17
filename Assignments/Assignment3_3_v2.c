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
    char name1[257];
    char name2[257];


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
        sprintf(name1,"%s/%s",argv[1],entry->d_name);
        sprintf(name2,"%s/%s",argv[2],entry->d_name);

        rename(name1,name2);
        
    }

        

    

    closedir(dp);

    return 0;
}