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
      fprintf(stderr, "Error: unsupported data type in kvp comparison\n");
      exit(EXIT_FAILURE); // Keys are different
    }
  } else {
    // Keys are of different type, compare based on enum value
    return (int)(kvpA->key.type) - (int)(kvpB->key.type);
  }
}

int type_comparison(DataContainer *a, DataContainer *b) {
  int comparison;
  if (a->type == b->type) {
    comparison = 0;
    switch (a->type) {
    case INT:
      comparison = compareInts(a->data, b->data);
      break;
    case FLOAT:
      comparison = compareFloats(a->data, b->data);
      break;
    case STRING:
      comparison = compareStrings(a->data, b->data);
      break;
    default:
      printf("Unsupported data type");
      comparison = NULL;
      break;
    }
  }
  return comparison;
}

int compareNode(void *a, void *b) {
  Node *nodeA = (Node *)a;
  Node *nodeB = (Node *)b;

  if (nodeA->data.type == nodeB->data.type) {
    int comparison = type_comparison(&nodeA->data, &nodeB->data);

    if (comparison == 0) {
      return comparison;
    } else {
      fprintf(stderr, "Error: unsupported data type in node comparison\n");
      exit(EXIT_FAILURE);
    }
  } else {
    return (int)(nodeA->data.type) - (int)(nodeB->data.type);
  }
}

int compareTreeNode(void *a, void *b) {
  TreeNode *nodeA = (TreeNode *)a;
  TreeNode *nodeB = (TreeNode *)b;

  if (nodeA->data.type == nodeB->data.type) {
    int comparison = type_comparison(&nodeA->data, &nodeB->data);

    if (comparison == 0) {
      return comparison;
    } else {
      fprintf(stderr, "Error: unsupported data type in node comparison\n");
      exit(EXIT_FAILURE);
    }
  } else {
    return (int)(nodeA->data.type) - (int)(nodeB->data.type);
  }
}

void set_function_ptrs(DataFuncPtrs *ptrs, DataType *type) {
  switch (*type) {
  case INT:
    ptrs->print = &printInt;
    ptrs->compare = &compareInts;
    ptrs->size = sizeof(int);
    break;
  case FLOAT:
    ptrs->print = &printFloat;
    ptrs->compare = &compareFloats;
    ptrs->size = sizeof(float);
    break;
  case STRING:
    ptrs->print = &printString;
    ptrs->compare = &compareStrings;
    ptrs->size = sizeof(char *);
    break;
  case KVP: // KeyValuePair - Used in HashMaps
    ptrs->print = &printKVP;
    ptrs->compare = &compareKVP;
    ptrs->size = sizeof(KeyValuePair);
    break;
  case NODE:
    ptrs->print = &printNode;
    ptrs->compare = &compareNode;
    ptrs->size = sizeof(Node);
    break;
  case TREENODE:
    ptrs->print = &printTreeNode;
    ptrs->compare = &compareTreeNode;
    ptrs->size = sizeof(TreeNode);
    break;
  default:
    fprintf(stderr, "Error: unsupported data type in list creation\n");
    exit(EXIT_FAILURE);
  }
}
