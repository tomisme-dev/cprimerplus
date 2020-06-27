
#include <limits.h>
#include <stdio.h>

void modify(int *i) {
    (*i)++;
}

int main(int argc, char const *argv[])
{
    const int x = 14;
    int *p = (int *)&x;
    modify(p);
    printf("INT_MAX=%lld\n", LLONG_MAX);
    return 0;
}

