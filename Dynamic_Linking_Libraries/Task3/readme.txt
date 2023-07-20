
executable name : Myexe
c files : sharedfile.c sharedfile1.c, client.c
header files : sharedfile.h
obj files : sharedfile.o sharedfile1.o
shared objects :  library.so, library1.so
Program Description :
                      1. library.so is for Addition Function which is defined in sharedfile.c
                      2. library1.so loads the library.so.
                      3. sharedfile.h conatains prototypes of Functions
                      4. client.c loads library1.so.

Execution tips:
                      1. for library loading, absolute path is used(for dynamic loading from . directory)

Execution Commands:
                      1. gcc -c fPIC sharedfile.c
                      2. gcc -shared -o library.so sharedfile.o
                      3. gcc -c fPIC sharedfile1.c
                      4. gcc -shared -o library1.so sharedfile1.o 
                      5. gcc -rdynamic -o Myexe client.c
                                               
                                                                              
