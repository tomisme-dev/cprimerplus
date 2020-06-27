#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char name[] = "你好";
    printf("%s\n, arr size: %ld, str len: %d\n", name, sizeof(name), strlen(name));
    return 0;
}
