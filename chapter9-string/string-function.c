#include <string.h>
#include <stdio.h>

void f()
{
    char arr[] = "hello";
    char *str1 = "hello";
    char *str2 = "ello";

    printf("arr=%p, str1=%p, str2=%p\n", arr, str1, str2);
}

void f2()
{
    char *mytalents[] = {
        "Adding numbers swiftly",
        "Multiplying accurately", "Stashing data",
        "Following instructions to the letter",
        "Understanding the C language"};
    mytalents[0][0] = 'B';
}

void f3()
{
    // 字符串常量数组
    char *arr1[] = {
        "hello",
        "my world2"
    };

    // 字符二维数组
    char arr2[][10] = {
        "hello",
        "my world2"
    };

    printf("size1=%ld, size2=%ld\n", sizeof(arr1), sizeof(arr2));
    printf("arr[0]=%p, arr[1]=%p\n", arr1[0], arr1[1]);
    printf("arr2[0]=%p, arr2[1]=%p\n", arr2[0], arr2[1]);


}

void f4() {
    char arr[] = "abcd";
    char arr2[] = {'a', 'b', 'c', 'd'};
    printf("len=%ld\n", sizeof(arr)/ sizeof(char));
    printf("len=%ld\n", sizeof(arr2)/ sizeof(char));
}

int main(int argc, char const *argv[])
{
    puts("hello");
    puts("world");
    char buf[1024];
    f();
    f3();
    // fgets(buf, 1024, stdin);
    f4();

    // printf("read:%s*", buf);
    return 0;
}
