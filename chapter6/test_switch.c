#include <stdio.h>


int main(int argc, char const *argv[])
{
    int c = getchar();

    switch (c)
    {
    case 'a':
        printf("you input a");
        break;
    case 'b':
        printf("you input b");
        break;
    default:
        printf("you input another");
        break;
    }
    return 0;
}
