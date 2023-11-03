// binary_tree.c

#include "data_structures/binary_tree.h"
#include "utils/data_types.h"

TreeNode *treenode_create(DataType type, void *value, size_t size) {
  if (value == NULL) {
    fprintf(stderr, "Null data error\n");
    exit(EXIT_FAILURE);
  }

  // Create the TreeNode
  TreeNode *tnode = malloc(sizeof(TreeNode));
  if (!tnode) {
    fprintf(stderr, "Unable to allocate memory for node\n");
    exit(EXIT_FAILURE);
  }

  // Allocate memory and store the data
  tnode->data.data = malloc(size);
  if (!tnode->data.data) {
    fprintf(stderr, "Unable to allocate memory for data\n");
    exit(EXIT_FAILURE);
  }
  memcpy(tnode->data.data, value, size);
  tnode->data.type = type;
  tnode->left = NULL;
  tnode->right = NULL;

  return tnode;
}

BinaryTree *binarytree_create(DataType type) {
  BinaryTree *tree = malloc(sizeof(BinaryTree));
  if (!tree) {
    fprintf(stderr, "Unable to allocate memory for tree");
    exit(EXIT_FAILURE);
  }

  tree->type = type;
  tree->left = NULL;
  tree->right = NULL;
  tree->funcs = malloc(sizeof(DataFuncPtrs));
  tree->node_count = 0; // TODO: double check if this is meant to be 1

  // Assign the type-specific functions
  set_function_ptrs(tree->funcs, &type);
  return tree;
}
