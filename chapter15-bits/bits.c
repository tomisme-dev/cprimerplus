#include <stdio.h>
#include <string.h>

struct bits
{
    unsigned char is_man: 1;
    unsigned char is_woman: 2;
};  


int main(int argc, char const *argv[])
{
    struct bits bs;
    bs.is_man = 1;
    bs.is_woman = 2;

    printf("%d, %d, size: %zd\n", bs.is_man, bs.is_woman, sizeof(struct bits));
    return 0;
}

