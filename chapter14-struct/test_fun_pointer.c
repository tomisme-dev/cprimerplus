#include <stdio.h>


typedef void (*t_f1)(void);

typedef void (*t_f2)(void);


void fun1() {
    printf("fun1...\n");
}

void fun2() {
    printf("fun1...\n");
}


void call1(t_f1 f) {
    f();
}


void call2(t_f2 f) {
    f();
}


int main(int argc, char const *argv[])
{
    t_f1 f1 = fun1;

    call1(f1);
    call2(f1);

    return 0;
}
