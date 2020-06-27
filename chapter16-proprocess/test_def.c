
#include "define.h"
#include "define.h"

#if SYS == 1
    #define A 11
#elif SYS == 2
    #define A 22
#else
    #define A 33
#endif

#if defined (ER)
    #error my error
#endif


#include <stdio.h>

void why_me()
{
    printf("This function is %s\n", __func__);
    printf("This is line %d.\n", __LINE__);
}


int main(int argc, char const *argv[])
{
    int size = SIZE;

    int a = A;

    why_me();
    
    return 0;
}
