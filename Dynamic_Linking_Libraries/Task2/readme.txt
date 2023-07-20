
executable name : Myexe
c files : NumbersSharedfile.c, NumberClient.c
header files : NumbersSharedfile.h
obj files : NumbersSharedfile.o
shared objects :  Numbers.so
Program Description :
                      1. Numbers.so is contains two function Add and Sub which is defined in NumbersSharedfile.c
                      2. NumbersSharedfile.h conatains prototypes of Functions
                      3. NumberClient.c load the libraries and call functions.

Execution tips:
                      1. for library loading, absolute path is used(for dynamic loading from . directory)

Execution Commands:
                      1. gcc -c fPIC NumbersSharedfile.c
                      2. gcc -shared -o Numbers.so NumbersSharedfile.o
                      3. gcc -rdynamic -o Myexe NumberClient.c
                                               
                                                                              
