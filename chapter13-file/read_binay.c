#include <stdio.h>

#define SIZE 64

void print_arr(unsigned char buf[], size_t len)
{
    for (int i = 0; i < len; i++)
    {
        if (i % 16 == 0)
        {
            printf("\n");
        }
        printf("%02x ", buf[i]);
    }
}

int main(int argc, char const *argv[])
{
    FILE *file = fopen("hello.o", "r");
    
    unsigned char buf[SIZE];
    size_t read_count;
    while ((read_count = fread(buf, sizeof(char), SIZE, file)) > 0)
    {
        print_arr(buf, read_count);
    }

    fclose(file);
    return 0;
}
