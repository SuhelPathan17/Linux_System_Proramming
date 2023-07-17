#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

#pragma pack(1)
struct Employee
{
    int EmpId;
    char Sname[20];
    int Age;
};

int main(int argc, char *argv[])
{
    struct Employee sobj;
    int fd = 0;

    if(argc != 2)
    {
        printf("Insufficient Arguments\n");
        return -1;
    }

    sobj.EmpId = 11;
    sobj.Age = 25;
    strcpy(sobj.Sname,"Rahul");


    fd = open(argv[1],O_RDONLY);

    read(fd,&sobj,sizeof(sobj));

    printf("Name : %s  \n",sobj.Sname);
    printf("Id : %d  \n",sobj.EmpId);
    printf("Age : %d  \n",sobj.Age);

    close(fd);

    return 0;
}