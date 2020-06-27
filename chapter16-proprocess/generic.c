#include <stdio.h>

#define TYPE(X) _Generic((X), \
    int: "int", \
    double: "double", \
    default: "other" \
)

int main(int argc, char const *argv[])
{
    double x = 9.0;
    int y = 12;
    float z = 45;

    char * type = _Generic((9), int: "int", double: "double", default: "other" );
    printf("%s\n", TYPE(x));
    printf("%s\n", TYPE(y));
    printf("%s\n", TYPE(z));
    printf("%s\n", type);
    return 0;
}
