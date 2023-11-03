#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#include "data_structures/queue.h"
#include "utils/data_types.h"

typedef struct BinaryTree {
  DataType type;
  TreeNode *root;
  DataFuncPtrs *funcs;
  int node_count;
} BinaryTree;

BinaryTree *binarytree_create(DataType type);
TreeNode *treenode_create(DataType type, void *data, size_t data_size);
void binarytree_insert(BinaryTree *tree, void *data);

#endif // BINARY_TREE_H
