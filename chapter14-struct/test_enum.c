#include <stdio.h>


int main(int argc, char const *argv[])
{
    enum color {red, green, blue};
    enum color c1 = red;
    enum color c2 = green;
    enum color c3 = blue;

    printf("%d", c1);
    return 0;
}
