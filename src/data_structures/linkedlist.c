// linkedlist.c
#include "data_structures/linkedlist.h"

// Function to create a node with data
Node *node_create(DataType type, void *value, size_t size) {
  if (value == NULL) {
    fprintf(stderr, "Null data error\n");
    exit(EXIT_FAILURE);
  }

  // Create the node
  Node *node = (Node *)malloc(sizeof(Node));
  if (!node) {
    fprintf(stderr, "Unable to allocate memory for node\n");
    exit(EXIT_FAILURE);
  }

  // Allocate memory and store the data
  node->data.data = malloc(size);
  if (!node->data.data) {
    fprintf(stderr, "Unable to allocate memory for data\n");
    free(node);
    exit(EXIT_FAILURE);
  }
  memcpy(node->data.data, value, size);
  node->data.type = type; // Ensure the type is consistent
  node->next = NULL;

  return node;
}

// Function to initialise the linked list with a specific type
LinkedList *llist_create(DataType type) {
  LinkedList *list = malloc(sizeof(LinkedList));
  if (!list) {
    fprintf(stderr, "Error: out of memory\n");
    exit(EXIT_FAILURE);
  }

  list->type = type;
  list->head = NULL;

  // Assign the type-specific functions and determine data size based on type
  switch (type) {
  case INT:
    list->printFunc = &printInt;
    list->compareFunc = &compareInts;
    list->dataSize = sizeof(int);
    break;
  case FLOAT:
    list->printFunc = &printFloat;
    list->compareFunc = &compareFloats;
    list->dataSize = sizeof(float);
    break;
  case STRING:
    list->printFunc = &printString;
    list->compareFunc = &compareStrings;
    list->dataSize = sizeof(char *);
    break;
  case KVP: // KeyValuePair - Used in HashMaps
    list->printFunc = &printKVP;
    list->compareFunc = &compareKVP;
    list->dataSize = sizeof(KeyValuePair);
    break;
  default:
    fprintf(stderr, "Error: unsupported data type in list creation\n");
    free(list);
    exit(EXIT_FAILURE);
  }
  return list;
}

void llist_append(LinkedList *list, void *data) {
  if (!data) {
    fprintf(stderr, "Error: data is NULL\n");
    return;
  }

  Node *new_node = node_create(list->type, data, list->dataSize);
  if (list->head == NULL) {
    list->head = new_node;
    return;
  }

  Node *last = list->head;
  while (last->next != NULL) {
    last = last->next;
  }
  last->next = new_node;
}

void llist_fromarr(LinkedList *list, void *data, int length) {
  if (!data) {
    fprintf(stderr, "Error: data is NULL\n");
    return;
  }
  for (int i = 0; i < length; i++) {
    void *item = (char *)data + i * list->dataSize;
    llist_append(list, item);
  }
}

void *llist_removefront(LinkedList *list) {
  Node *temp = list->head;
  list->head = list->head->next;
  return temp->data.data;
}

void llist_delete(LinkedList *list, void *data) {
  if (list->head == NULL)
    return;

  Node *temp = list->head;
  Node *prev = NULL;

  if (list->compareFunc(temp->data.data, data) == 0) {
    list->head = temp->next;
    free(temp->data.data);
    free(temp);
    return;
  }

  while (temp != NULL && list->compareFunc(temp->data.data, data) != 0) {
    prev = temp;
    temp = temp->next;
  }

  if (temp == NULL)
    return;

  prev->next = temp->next;

  free(temp->data.data);
  free(temp);
}

void llist_print(LinkedList *list) {
  Node *temp = list->head;
  int isFirst = 1;
  while (temp != NULL) {
    // Use function pointer to print the data
    if (!isFirst) {
      printf(" -> ");
    }
    list->printFunc(temp->data.data);
    isFirst = 0;
    temp = temp->next;
  }
  printf("\n");
}

void llist_free(LinkedList *list) {
  Node *current = list->head;
  Node *next;

  while (current) {
    next = current->next;
    free(current->data.data);
    free(current);
    current = next;
  }
  free(list);
}
