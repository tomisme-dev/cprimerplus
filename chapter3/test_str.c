#include <stdio.h>


int main(int argc, char const *argv[])
{
    char name[1024];
    printf("please input you name.\n");
    // scanf("%s", name);
    fgets(name, 1024, stdin);
    printf("your name is %s!\n", name);
    return 0;
}
