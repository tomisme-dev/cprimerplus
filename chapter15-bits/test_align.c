#include <stdio.h>
#include <stdalign.h>

int main(int argc, char const *argv[])
{
    double d = 12;
    char _Alignas(double) c = 'a';
    long size = _Alignof(float);
    size_t size2 = alignof(double);
    printf("%ld. %ld\n", size, size2);
    return 0;
}
