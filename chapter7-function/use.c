#include <stdio.h>

extern int sum(int a, int b);


int main(int argc, char const *argv[])
{
    int x = sum(3, 2);
    printf("sum = %d\n", x);
    return 0;
}
