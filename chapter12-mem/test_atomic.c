#include <stdatomic.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    _Atomic int count = 0;

    atomic_store(&count, 12);
    atomic_fetch_add(&count, 10);
    printf("count=%d", count);
    return 0;
}
