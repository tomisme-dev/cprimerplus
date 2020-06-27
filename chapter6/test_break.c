#include <stdio.h>
#include <dirent.h>
#include <limits.h>

int main(int argc, char const *argv[])
{
    int i = 0;
    int j = 1;
    for(i = 0; i < 10; i++) {
        for(j = i; j < 9; j++) {
            goto outer;
        }
    }

    outer: 
    printf("i=%d, j=%d\n", i, j);
    return 0;
}
