#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct A
{
    char *name;
    int (*get_name_len)(struct A *this);   
};

int get_name_len_A(struct A *this) {
    return strlen(this->name);
}


struct A *new_A() {
    struct A *a = (struct A *)malloc(sizeof(struct A));
    a->get_name_len = get_name_len_A;
    return a;
}






int main(int argc, char const *argv[])
{
    struct A *a = new_A();
    a->name = "tom2";
    printf("hello c primer plus, nameLen = %d\n", a->get_name_len(a));
    return 0;
}
