#include <stdio.h>

char get_first() {
    int c = getchar();
    while(getchar() != '\n') {
    }

    return c;
}

char get_choice(void)
{
    int ch;
    printf("Enter the letter of your choice:\n");
    printf("a. advice b. bell\n");
    printf("c. count q. quit\n");
    ch = get_first();
    while ((ch < 'a' || ch > 'c') && ch != 'q')
    {
        printf("Please respond with a, b, c, or q.\n");
        ch = get_first();
    }
    return ch;
}


int main(int argc, char const *argv[])
{
    while (1)
    {
        char c = get_choice();
        printf("get char: %c\n", c);
    }
    

    return 0;
}
