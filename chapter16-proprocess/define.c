#include <stdio.h>

#define F(x) #x#x"12"

// 处理前
#define F2(x) A##x##12 

#define PR(X, ...) printf("Message" #X ": " __VA_ARGS__)

int main(int argc, char const *argv[])
{
    char * s = F(hello);
    int F2(hello) = 9;
    PR(1, "age:%d\n", Ahello12);
    return 0;
}
