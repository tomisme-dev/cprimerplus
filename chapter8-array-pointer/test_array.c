#include <stdio.h>


int main(int argc, char const *argv[])
{
    int zippo[4][2] = { {2,4}, {6,8}, {1,3}, {5, 7} };
    int (* p2)[2] = zippo;
    for(int i = 0; i < 4; i++, p2++) {
        for(int j = 0; j < 2; j++) {
            printf("(%d, %d) = %d\n", i, j, (*p2)[j]);
        }
    }
    return 0;
}
