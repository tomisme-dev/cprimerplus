#include <stdio.h>


typedef void (*func)(char *);

void println(char *string);

void to_binary(unsigned long value) {
    if(value == 0) {
        return;
    }

    to_binary(value / 2);

    printf("%lu", (value % 2));
}

int main(int argc, char const *argv[])
{
    // func f = println;
    // f("world");
    // println("hello");

    to_binary(2);

    return 0;
}



void println(char *string) {
    printf("%s\n", string);
}