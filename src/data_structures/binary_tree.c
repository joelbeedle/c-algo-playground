// binary_tree.c

#include "data_structures/binary_tree.h"
#include "data_structures/queue.h"
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
  tree->root = NULL;
  tree->funcs = malloc(sizeof(DataFuncPtrs));
  tree->node_count = 0; // TODO: double check if this is meant to be 1

  // Assign the type-specific functions
  set_function_ptrs(tree->funcs, &type);
  return tree;
}

void binarytree_insert(BinaryTree *tree, void *data) {
  // create node with data
  // use a queue to iterate through the tree (BFS)
  // means we need to use a queue with a node type !
  TreeNode *new_node = treenode_create(tree->type, data, tree->funcs->size);
  if (!new_node) {
    fprintf(stderr, "Unable to allocate memory for TreeNode");
    exit(EXIT_FAILURE);
  }
  if (!tree->root) {
    tree->root = new_node;
  } else {
    Queue *queue = queue_create(TREENODE);
    queue_enq(queue, tree->root);

    // while the queue is not empty
    while (!queue->list->head) {
      TreeNode *temp = queue_deq(queue);

      if (temp->left == NULL) {
        temp->left = new_node;
        queue_free(queue);
        return;
      } else {
        queue_enq(queue, temp->left);
      }

      if (temp->right == NULL) {
        temp->right = new_node;
        queue_free(queue);
        return;
      } else {
        queue_enq(queue, temp->right);
      }
    }
    queue_free(queue);
  }
  tree->node_count++;
}
