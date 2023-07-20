
executable name : Myexe
c files : sharedfile.c sharedfile1.c, client.c
header files : sharedfile.h
obj files : sharedfile.o sharedfile1.o
shared objects :  library1.so, library2.so
Program Description :
                      1. library1.so is for Addition Function which is defined in sharedfile.c
                      2. library2.so is for Substraction Function which is defined in sharedfile1.c
                      3. sharedfile.h conatains prototypes of Functions
                      4. client.c loads both the libraries and call functions.

Execution tips:
                      1. for library loading, absolute path is used(for dynamic loading from . directory)

Execution Commands:
                      1. gcc -c fPIC sharedfile.c
                      2. gcc -shared -o library1.so sharedfile.o
                      3. gcc -c fPIC sharedfile1.c
                      4. gcc -shared -o library2.so sharedfile1.o 
                      5. gcc -rdynamic -o Myexe client.c
                                               
                                                                              
