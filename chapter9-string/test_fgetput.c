#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char buf[4];
    while(fgets(buf, 4, stdin) != NULL) {
        printf("strlen=%ld\n", strlen(buf));
        fputs(buf, stdout);
    }
    return 0;
}
