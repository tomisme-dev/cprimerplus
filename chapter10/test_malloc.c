#include <stdio.h>
#include <stdlib.h>

int a = 12;

void f1() {}
void f2() {}
void f3() {}

int main(int argc, char const *argv[])
{
    int b = 9;
    int *c = (int *)malloc(sizeof(int));

    printf("pa=%p, pb=%p, pc=%p\n", &a, &b, c);
    printf("f1=%p, f2=%p, f3=%p\n", f1, f2, f3);
    return 0;
}
