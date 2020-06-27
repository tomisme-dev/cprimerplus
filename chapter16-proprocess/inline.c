#include <stdio.h>

inline static int sum(int a, int b) __attribute__((always_inline));

inline static int sum(int a, int b) {
    return a + b;
}

inline static void eat() {
    while(getchar() != '\n') {

    }
}

static inline int
inc (int *a)
{
  return (*a)++;
}


int main(int argc, char const *argv[])
{
    int x = sum(8, 9);
    eat();
    int m = 18;
    inc(&m);
    printf("%d, %d", x, m);
    return 0;
}
