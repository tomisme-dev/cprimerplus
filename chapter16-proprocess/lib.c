#include <stdlib.h>
#include <stdio.h>


void my_exit() {
    puts("exit....");
}

int cmp_double(const void * a, const void *b) {
    const double *d1 = a;
    const double *d2 = b;

    return *d1 > *d2 ? 1 :(*d1 == *d2 ? 0 : -1);
}

void show_array(int size, double d[size]) {
    for(int i = 0; i < size; i++) {
        printf("%f, ", d[i]);
    }

    puts(" ");
}

int main(int argc, char const *argv[])
{
    atexit(my_exit);

    double ds[] = {5.9, 5.6, 3.1, 8.75, 1.58, 3.78};
    int len = sizeof(ds)/sizeof(double);
    show_array(len, ds);
    qsort((void *)ds, len, sizeof(double), cmp_double);
    show_array(len, ds);
    puts("after finish....");


    return 0;
}
