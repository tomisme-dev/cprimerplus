#include <stdio.h>
#include <stdlib.h>


int * alloc(size_t size) {
    int *ptr = (int *)malloc(sizeof(int) * size);
    return ptr;
}

struct student {
    int age;
    struct {
        char letf[20];
        char right[20];
    };
};

typedef struct student s_student;

int main(int argc, char const *argv[])
{
    s_student s1 = {12, {"left hand", "right hand"}};
    printf("%s, %s, %d\n", s1.letf, s1.right, s1.age);
    return 0;
}
