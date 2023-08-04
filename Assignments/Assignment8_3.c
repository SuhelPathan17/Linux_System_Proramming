#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int Ret2 = 0;
    int Ret3 = 0;
    int Ret4 = 0;
    
    Ret2 = fork();
    if(Ret2 == 0)  // Child  
    {
        
        execl("./Process2","NULL",NULL);
        
    }
    
    Ret3 = fork();
    if(Ret3 == 0)  // Child  
    {
        execl("./Process3","NULL",NULL);
    }

    Ret4 = fork();
    if(Ret4 == 0)  // Child  
    {
        execl("./Process4","NULL",NULL);
    }
   
   
    

    return 0;
}

