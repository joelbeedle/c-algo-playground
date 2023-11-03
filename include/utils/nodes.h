#ifndef NODES_H
#define NODES_H

#include "utils/data_types.h"

typedef struct Node Node;
typedef struct TreeNode TreeNode;

struct Node {
  DataContainer data; // Data with its type
  struct Node *next;  // Pointer to the next node
};

struct TreeNode {
  DataContainer data;
  struct TreeNode *left;
  struct TreeNode *right;
};

#endif // NODES_H
