#include <stdio.h>

int sum2d(int row, int col, int ar[row][col]);

int main(int argc, char const *argv[])
{
    int ar[][2] = {{1, 2}, {3, 4}, {5, 6}};

    int s = sum2d(sizeof(ar) / sizeof(ar[0]), 2, ar);
    printf("sum=%d\n", s);
    return 0;
}

int sum2d(int row, int col, int ar[row][col])
{
    int s = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            s += ar[i][j];
        }
    }
    return s;
}
