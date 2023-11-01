#ifndef QUEUE_H
#define QUEUE_H

#include "data_structures/linkedlist.h"
#include "utils/data_types.h"

typedef struct Queue {
  LinkedList *list;
} Queue;

Queue *queue_create(DataType type);
void queue_enq(Queue *q, void *data);
void *queue_deq(Queue *q);
void *queue_peek(Queue *q);

#endif // QUEUE_H
