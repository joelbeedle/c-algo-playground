#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#include "utils/data_types.h"
#include "utils/nodes.h"

typedef struct BinaryTree {
  DataType type;
  TreeNode *left;
  TreeNode *right;
  DataFuncPtrs *funcs;
  int node_count;
} BinaryTree;

BinaryTree *binarytree_create(DataType type);
TreeNode *treenode_create(DataType type, void *data, size_t data_size);
void insertNode(BinaryTree *tree, TreeNode *node);

#endif // BINARY_TREE_H
