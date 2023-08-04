#include"sharedfile.h"
#include<stdio.h>
#include<stdbool.h>

int Factorial(int iNo)
{
    int iCnt = 0;
    int iFact = 1;

    for(iCnt = 1; iCnt <=iNo; iCnt++)
    {
        iFact = iFact * iCnt;
    }

    return iFact;
}