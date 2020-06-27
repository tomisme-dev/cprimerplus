#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "names_st.h"

void get_names(names *name) {
    char temp[1024];
    printf("请输入firstname:\n");
    s_gets(temp, 1024);
    strcpy(name->first, temp);
    

    printf("请输入lastname:\n");
    s_gets(temp, 1023);
    strcpy(name->last, temp);
    
}


void show_names(const names *name) {
    printf("first name: %s, last name: %s\n", name->first, name->last);
}


char * s_gets(char * st, int n) {
    fgets(st, n, stdin);
    for(char *s = st; s < (st + n); s++) {
        if(*s == '\n') {
            *s = '\0';
            break;
        }
    }

    return st;
}


// int main(int argc, char const *argv[])
// {
//     names n;
//     get_names(&n);
//     show_names(&n);
//     return 0;
// }
