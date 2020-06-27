#include <stdlib.h>
#include <stdio.h>

#include "queue.h"

static void CopyToItem(Node * pn, Item * pi);


void InitializeQueue(Queue * pq) {
    pq->front = NULL;
    pq->rear = NULL;
    pq->items = 0;
}

bool QueueIsFull(const Queue * pq) {
    Node *tmp = malloc(sizeof(Node));
    if(tmp == NULL) {
        fprintf(stderr, "out of memory\n");
        return true;
    }

    return false;
}

bool QueueIsEmpty(const Queue *pq) {
    if(pq == NULL || pq->items == 0) {
        return true;
    }

    return false;
}

int QueueItemCount(const Queue * pq) {
    if(QueueIsEmpty(pq)) {
        return 0;
    }

    return pq->items;
}

bool EnQueue(Item item, Queue * pq) {
    if(QueueIsFull(pq)) {
        return false;
    }

    Node *pn = malloc(sizeof(Node));
    pn->item = item;
    pn->next = NULL;

    if(pq->rear == NULL) {
        pq->rear = pn;
    } else {
        pq->rear->next = pn;
        pq->rear = pn;
    }

    if(pq->front == NULL) {
        pq->front = pn;
    }

    pq->items++;
    return true;
}

bool DeQueue(Item *pitem, Queue * pq) {
    if(QueueIsEmpty(pq)) {
        return false;
    }

    Node *front = pq->front;
    CopyToItem(front, pitem);

    if(pq->items == 1) {
        pq->front = NULL;
        pq->rear = NULL;
    } else {
        pq->front = pq->front->next;
    }

    pq->items--;

    free(front);

    return true;
}

static void CopyToItem(Node * pn, Item * pi)
{
    *pi = pn->item;
}

void EmptyTheQueue(Queue * pq) {
    Node *cur = pq->front;
    while(cur != NULL) {
        Node *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
}