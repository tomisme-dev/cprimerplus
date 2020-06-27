#include <stdio.h>
#include <string.h>

typedef struct student
{
    char name[64];
    int age;
} t_student;


int main(int argc, char const *argv[])
{
    t_student s;
    strcpy(s.name, "tome");
    s.age = 12;
    printf("%s, %d\n", s.name, s.age);

    t_student s2 = {"jerry", 18};

    t_student s4 = s2;
    s4.age = 16;
    printf("%s, %d\n", s2.name, s2.age);
    printf("%p, %p, %p\n", &s, &s2, &s4);


    t_student s3 = {
        .age = 12,
        .name = "steven"
    };

    s3 = s2;

    return 0;
}
