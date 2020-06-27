#include <stdio.h>
#include <ctype.h>

#define SPACE ' '

int main(int argc, char const *argv[])
{
    int c = 0;
    int prev_is_alpha = 1;
    int word_count = 0;

    
    while((c = getchar()) != EOF) {
        if(!isalpha(c) && prev_is_alpha) {
            word_count++;
        }
        prev_is_alpha = isalpha(c);
    }

    if(prev_is_alpha) {
        word_count++;
    }

    printf("world count=%d\n", word_count);
    return 0;
}
