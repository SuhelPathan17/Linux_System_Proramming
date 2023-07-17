#include<stdio.h>

int main(int argc, char *argv[])
{
    int iNo1 = 0, iNo2 = 0;
    int iAns = 0;

    scanf("%d",&iNo1);
    scanf("%d",&iNo2);

    iAns = iNo1 + iNo2;

    printf("Addition is : %d\n",iAns);

    return 0;
}


// To Run Program:

// gcc Assignement4_1.c -o Myexe
// ./Myexe > output.txt < input.txt