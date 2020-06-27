#include <stdio.h>

int main(int argc, char const *argv[])
{
    union {
        int x;
        unsigned char c;
    } u;

    u.x = 0x1234;
    u.c = 8;
    printf("%x, %x\n", u.x, u.c);
    return 0;
}
