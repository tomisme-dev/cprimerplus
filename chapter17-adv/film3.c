#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void showMovie(Item item) {
    printf("title:%s, rate: %d\n", item.title, item.rating);
}


int main(int argc, char const *argv[])
{
    List movies;

    // 初始化
    InitializeList(&movies);

    if(ListIsFull(&movies)) {
        fprintf(stderr, "memory is oom, bye....\n");
        exit(EXIT_FAILURE);
    }

    // 读数据
    for(int i = 1; i < 10; i++) {
        Item item;
        strcpy(item.title, "movie");
        item.title[5] = '0' + i;
        item.title[6] = '\0';
        item.rating = i;

        AddItem(item, &movies);
    }

    // 展示数据
    Traverse(&movies, showMovie);

    // 清空list
    EmptyTheList(&movies);


    return 0;
}
