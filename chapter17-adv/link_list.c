#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    void *value;
    struct node *next;
} t_node;

void show_list(t_node *head) {
    t_node *tmp;
    for(tmp = head; tmp != NULL; tmp = tmp->next) {
        int *val = (int *)tmp->value;
        printf("%d\n", *val);
    }
}

void free_list(t_node *head) {
    while (head != NULL)
    {
        t_node *tmp = head;
        head = head->next;
        free(tmp->value);
        free(tmp);
    }
    
}


int main(int argc, char const *argv[])
{
    t_node *head = NULL, *prev = NULL;
    for(int i = 0; i < 10; i++) {
        t_node *cur = malloc(sizeof(t_node));
        cur->value = malloc(sizeof(int));
        *((int *)cur->value) = i * i;

        if(head == NULL) {
            head = cur;
        } else {
            prev->next = cur;
        }

        prev = cur;
    }
    
    // printf("%d\n", *((int *)head->value));
    show_list(head);
    free(head);
    return 0;
}
