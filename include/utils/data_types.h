#ifndef DATA_TYPES_H
#define DATA_TYPES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Enum to define the supported data types
typedef enum DataType {
  INT,
  FLOAT,
  STRING,
  KVP,
  NODE,
  TREENODE,
} DataType;

// Container for the data, associating a type with the generic data pointer
typedef struct DataContainer {
  DataType type;
  void *data;
} DataContainer;

// KeyValuePair Data structure
typedef struct KeyValuePair {
  DataContainer key;
  DataContainer value;
} KeyValuePair;

typedef struct Node {
  DataContainer data; // Data with its type
  struct Node *next;  // Pointer to the next node
} Node;

typedef struct TreeNode {
  DataContainer data;
  struct TreeNode *left;
  struct TreeNode *right;
} TreeNode;

typedef struct DataFuncPtrs {
  size_t size; // size of the type  TODO: investigate moving this
  void (*print)(void *);
  int (*compare)(void *, void *);
} DataFuncPtrs;

// Function declarations related to data types
// Printing Functions
void printInt(void *data);
void printFloat(void *data);
void printString(void *data);
void printKVP(void *data);
void printNode(void *data);
void printTreeNode(void *data);

// Comparing Functions
int compareInts(void *a, void *b);
int compareFloats(void *a, void *b);
int compareStrings(void *a, void *b);
int compareKVPs(void *a, void *b);
int compareNodes(void *a, void *b);
int compareTreeNodes(void *a, void *b);

void set_function_ptrs(DataFuncPtrs *ptrs, DataType *type);

#endif // DATA_TYPES_H
