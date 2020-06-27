#include <stdlib.h>
#include <stdio.h>


#define SIZE 4*1024

int main(int argc, char const *argv[])
{
    int *p = malloc(SIZE * sizeof(int));
    printf("p1=%p\n", p);

    // free(p);
    int *p2 = malloc(1 * sizeof(int));
    printf("p2=%p\n", p2);
    printf("count=%#lx\n", (p2-p)*4);
    return 0;
}
