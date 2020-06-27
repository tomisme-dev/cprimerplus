#include <stdio.h>
#include "queue.h"




void ShowQueue(Queue *qp) {
    Node *cur = qp->front;
    while(cur != NULL) {
        printf("%ld, %d\n", cur->item.arrive, cur->item.processItem);
        cur = cur->next;
    }

    puts("");
}


int main(int argc, char const *argv[])
{
    Queue queue;
    Queue *qp = &queue;
    InitializeQueue(qp);

    for(int i = 1; i < 10; i++) {
        Item item;
        item.arrive = i * i;
        item.processItem = i * i * i;
        EnQueue(item, qp);
    }

    ShowQueue(qp);

    Item item;
    while(DeQueue(&item, qp)) {
        printf("dequeue: %ld, %d\n", item.arrive, item.processItem);
    }


    printf("queue size: %d\n", QueueItemCount(qp));

    
    return 0;
}
