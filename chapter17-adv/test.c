#include <stdio.h>


struct tt
{
    int x;
    char c;
};




int main(int argc, char const *argv[])
{
    struct tt t1 = {12, 13};
    struct tt t2;
    t2 = t1;
    t2.x = 99;
    printf("%d, %d\n", t1.x, t1.c);
    printf("%d, %d\n", t2.x, t2.c);
    return 0;
}
