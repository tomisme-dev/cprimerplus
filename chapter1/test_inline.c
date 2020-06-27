
#include <stdio.h>

//函数定义为inline即:内联函数
static inline char *dbtest(int a)
{
    return (a % 2 > 0) ? "1" : "0";
}

int main()
{
    int i = 0;
    for (i = 1; i < 100; i++)
    {
        printf("i:%d    奇偶性:%s /n", i, dbtest(i));
    }
}