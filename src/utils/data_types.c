// data_types.c
#include "utils/data_types.h"

// Implementation of functions declared in DataTypes.h

void printInt(void *data) {
  // Ensure data is not NULL before dereferencing it
  if (data) {
    printf("%d", *(int *)data);
  }
}

void printFloat(void *data) {
  // Ensure data is not NULL before dereferencing it
  if (data) {
    printf("%f", *(float *)data);
  }
}

void printString(void *data) {
  if (data) {
    printf("%s", (char *)data);
  }
}

void printKVP(void *data) {
  KeyValuePair *kvp = (KeyValuePair *)data;
  switch (kvp->key.type) {
  case INT:
    printInt(kvp->key.data);
    break;
  case FLOAT:
    printFloat(kvp->key.data);
    break;
  case STRING:
    printString(kvp->key.data);
    break;
  default:
    printf("Unsupported data type\n");
    break;
  }

  printf(": ");
  switch (kvp->value.type) {
  case INT:
    printInt(kvp->value.data);
    break;
  case FLOAT:
    printFloat(kvp->value.data);
    break;
  case STRING:
    printString(kvp->value.data);
    break;
  default:
    printf("Unsupported data type\n");
    break;
  }
}

void printNode(void *data) {
  Node *node = (Node *)data;
  switch (node->data.type) {
  case INT:
    printInt(node->data.data);
    break;
  case FLOAT:
    printFloat(node->data.data);
    break;
  case STRING:
    printString(node->data.data);
    break;
  default:
    printf("Unsupported data type\n");
    break;
  }
}

void printTreeNode(void *data) {
  TreeNode *node = (TreeNode *)data;
  switch (node->data.type) {
  case INT:
    printInt(node->data.data);
    break;
  case FLOAT:
    printFloat(node->data.data);
    break;
  case STRING:
    printString(node->data.data);
    break;
  default:
    printf("Unsupported data type\n");
    break;
  }
}

int compareInts(void *a, void *b) {
  // Before comparing, ensure pointers are not NULL to avoid dereferencing NULL
  // pointers
  if (!a || !b)
    return 0; // Or handle the error as suitable for your application

  int intA = *(int *)a;
  int intB = *(int *)b;
  return intA - intB; // 0 if equal, >0 if a is greater, <0 if b is greater
}

int compareFloats(void *a, void *b) {
  // Before comparing, ensure pointers are not NULL to avoid dereferencing NULL
  // pointers
  if (!a || !b)
    return 0; // Or handle the error as suitable for your application

  float floatA = *(float *)a;
  float floatB = *(float *)b;
  if (floatA == floatB)
    return 0;
  return floatA > floatB ? 1 : -1;
}

int compareStrings(void *a, void *b) {
  // Before comparing, ensure pointers are not NULL to avoid dereferencing NULL
  // pointers
  if (!a || !b)
    return 0; // Or handle the error as suitable for your application

  return strcmp((char *)a, (char *)b);
}

int compareKVP(void *a, void *b) {
  // Before comparing, ensure pointers are not NULL to avoid dereferencing NULL
  // pointers
  if (!a || !b)
    return 0;

  KeyValuePair *kvpA = (KeyValuePair *)a;
  KeyValuePair *kvpB = (KeyValuePair *)b;
  if (kvpA->key.type == kvpB->key.type) {
    int keyComparison = 0;
    switch (kvpA->key.type) {
    case INT:
      keyComparison = compareInts(kvpA->key.data, kvpB->key.data);
      break;
    case FLOAT:
      keyComparison = compareFloats(kvpA->key.data, kvpB->key.data);
      break;
    case STRING:
      keyComparison = compareStrings(kvpA->key.data, kvpB->key.data);
      break;
    default:
      printf("Unsupported data type\n");
      return 0;
    }
    if (keyComparison == 0) {
      return keyComparison; // Keys are the same
    } else {
      return NULL; // Keys are different
    }
  } else {
    // Keys are of different type, compare based on enum value
    return (int)(kvpA->key.type) - (int)(kvpB->key.type);
  }
}

int compareNode(void *a, void *b) {
  Node *nodeA = (Node *)a;
  Node *nodeB = (Node *)b;

  if (nodeA->data.type == nodeB->data.type) {
    int comparison = 0;
    switch (nodeA->data.type) {
    case INT:
      comparison = compareInts(nodeA->data.data, nodeB->data.data);
      break;
    case FLOAT:
      comparison = compareFloats(nodeA->data.data, nodeB->data.data);
      break;
    case STRING:
      comparison = compareStrings(nodeA->data.data, nodeB->data.data);
      break;
    default:
      printf("Unsupported data type");
      return 0;
    }
    if (comparison == 0) {
      return comparison;
    } else {
      return NULL;
    }
  } else {
    return (int)(nodeA->data.type) - (int)(nodeB->data.type);
  }
}

int compareTreeNode(void *a, void *b) {
  TreeNode *nodeA = (TreeNode *)a;
  TreeNode *nodeB = (TreeNode *)b;

  if (nodeA->data.type == nodeB->data.type) {
    int comparison = 0;
    switch (nodeA->data.type) {
    case INT:
      comparison = compareInts(nodeA->data.data, nodeB->data.data);
      break;
    case FLOAT:
      comparison = compareFloats(nodeA->data.data, nodeB->data.data);
      break;
    case STRING:
      comparison = compareStrings(nodeA->data.data, nodeB->data.data);
      break;
    default:
      printf("Unsupported data type");
      return 0;
    }
    if (comparison == 0) {
      return comparison;
    } else {
      return NULL;
    }
  } else {
    return (int)(nodeA->data.type) - (int)(nodeB->data.type);
  }
}

void set_function_ptrs(DataFuncPtrs *ptrs, DataType *type) {
  switch (*type) {
  case INT:
    ptrs->print_func = &printInt;
    ptrs->compare_func = &compareInts;
    ptrs->size = sizeof(int);
    break;
  case FLOAT:
    ptrs->print_func = &printFloat;
    ptrs->compare_func = &compareFloats;
    ptrs->size = sizeof(float);
    break;
  case STRING:
    ptrs->print_func = &printString;
    ptrs->compare_func = &compareStrings;
    ptrs->size = sizeof(char *);
    break;
  case KVP: // KeyValuePair - Used in HashMaps
    ptrs->print_func = &printKVP;
    ptrs->compare_func = &compareKVP;
    ptrs->size = sizeof(KeyValuePair);
    break;
  case NODE:
    ptrs->print_func = &printNode;
    ptrs->compare_func = &compareNode;
    ptrs->size = sizeof(Node);
    break;
  case TREENODE:
    ptrs->print_func = &printTreeNode;
    ptrs->compare_func = &compareTreeNode;
    ptrs->size = sizeof(TreeNode);
    break;
  default:
    fprintf(stderr, "Error: unsupported data type in list creation\n");
    exit(EXIT_FAILURE);
  }
}
