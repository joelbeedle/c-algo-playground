#ifndef TLLIST_H
#define TLLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils/data_types.h"
#include "utils/nodes.h"

typedef struct LinkedList LinkedList;

// Definition of the linked list structure
struct LinkedList {
  DataType type; // Type that the list is handling
  size_t dataSize;
  Node *head; // Head of the list
  DataFuncPtrs
      *funcs; // struct of function pointers to the type-specific functions
};

Node *node_create(DataType type, void *data, size_t dataSize);
LinkedList *llist_create(DataType type);
void llist_append(LinkedList *list, void *data);
void llist_fromarr(LinkedList *list, void *data, int length);
void *llist_removefront(LinkedList *list);
void llist_delete(LinkedList *list, void *data);
void llist_print(LinkedList *list);
void llist_free(LinkedList *list);

#endif // TLLIST_H
