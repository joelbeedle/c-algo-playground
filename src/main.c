// main.c
#include <stdio.h>
#include <stdlib.h>

#include "data_structures/hashmap.h"
#include "data_structures/linkedlist.h"
#include "data_structures/queue.h"
#include "data_structures/stack.h"

int main(int argc, char *argv[]) {
  int arr[3] = {1, 2, 3};

  LinkedList *list = llist_create(INT);
  llist_append(list, &arr[0]);
  llist_append(list, &arr[1]);
  llist_append(list, &arr[2]);
  llist_print(list);
  llist_delete(list, &arr[1]);
  llist_print(list);
  return 0;
}
