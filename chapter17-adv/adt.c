#include <stdlib.h>


#define TSIZE 64
struct film
{
    char title[TSIZE];
    int rating;
};

typedef struct film Item;

typedef struct node
{
    Item item;
    struct node *next;
} Node;

// typedef Node * List;

typedef struct list {
    Node *head;
    int size;
} List;

void InitializeList(List *plist) {
    plist->head = NULL;
    plist->size = 0;

}

int main(int argc, char const *argv[])
{
    List movies;
    InitializeList(&movies);
    return 0;
}



