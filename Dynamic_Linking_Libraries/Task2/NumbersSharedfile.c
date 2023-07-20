#include<stdio.h>
#include "NumbersSharedfile.h"


int Addition(int iNo1, int iNo2)
{
    int iAns = 0;

    iAns = iNo1 + iNo2;
    return iAns;
}

int Substraction(int iNo1, int iNo2)
{
    int iAns = 0;

    iAns = iNo1 - iNo2;
    return iAns;
}

int Multiplication(int iNo1, int iNo2)
{
    int iAns = 0;

    iAns = iNo1 * iNo2;
    return iAns;
}

int Factorial(int iNo)
{
    int iFact = 1;
    int iCnt = 0;

    for(iCnt = 1; iCnt <= iNo; iCnt++)
    {
        iFact = iFact * iCnt;
    }
     
    return iFact;
}

