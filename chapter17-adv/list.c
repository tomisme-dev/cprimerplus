#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void InitializeList(List *plist) {
    *plist = NULL;
}

bool ListIsEmpty(const List *plist) {
    if(*plist == NULL) {
        return true;
    }

    return false;
}

bool ListIsFull(const List *plist) {
    Node *pt;

    pt = malloc(sizeof(Node));

    if(pt == NULL) {
        return true;
    }

    free(pt);
    return false;
}

unsigned int ListItemCount(const List *plist) {

    unsigned int count = 0;
    Node *head = *plist;
    while(head != NULL) {
        count++;
        head = head->next;
    }

    return count;
}

bool AddItem(Item item, List *plist) {
    if(ListIsFull(plist)) {
        return false;
    }


    Node *n = malloc(sizeof(Node));
    n->item = item;
    n->next = NULL;

    Node *head = *plist;
    if(head == NULL) {
        *plist = n;
    } else {
        // 找链条的末端
        Node *tail = head;
        while(tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = n;
    }

    return true;
}

void Traverse(const List *plist, void (*pfun)(Item item)) {
    Node * cur = *plist;
    while(cur != NULL) {
        pfun(cur->item);
        cur = cur->next;
    }
}

void EmptyTheList(const List *plist) {
    // 释放内存
    Node * cur = *plist;
    while(cur != NULL) {
        Node *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
}