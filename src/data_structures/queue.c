// queue.c
#include "data_structures/queue.h"

Queue *queue_create(DataType type) {
  Queue *queue = malloc(sizeof(Queue));
  queue->list = llist_create(type);
  return queue;
}

void queue_enq(Queue *q, void *data) { llist_append(q->list, data); }

void *queue_deq(Queue *q) { return llist_removefront(q->list); }

void *queue_peek(Queue *q) { return q->list->head->data.data; }

void queue_free(Queue *q) {
  llist_free(q->list);
  free(q);
}
