// main.c
#include <stdio.h>
#include <stdlib.h>

#include "data_structures/hashmap.h"
#include "data_structures/linkedlist.h"
#include "data_structures/queue.h"
#include "data_structures/stack.h"

int main(int argc, char *argv[]) {
  int arr[3] = {1, 2, 3};

  Queue *q = queue_create(INT);
  queue_enq(q, &arr[0]);
  queue_enq(q, &arr[1]);
  queue_enq(q, &arr[2]);
  int *data = queue_deq(q);
  int *data2 = queue_deq(q);
  int *data3 = queue_peek(q);

  printf("%d\n", *data2);
  printf("%d\n", *data3);
  queue_free(q);
  return 0;
}
