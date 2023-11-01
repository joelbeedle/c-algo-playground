// hashmap.c
#include "data_structures/hashmap.h"

unsigned int hash(HashMap *hm, void *key) {
  unsigned int hashValue = 0;

  switch (hm->key_type) {
  case INT: {
    int *intKey = (int *)key;
    hashValue = *intKey;
    break;
  }
  case FLOAT: {
    unsigned int int_representation;
    memcpy(&int_representation, &key, sizeof(float));
    float *floatKey = (float *)key;
    hashValue = int_representation;
    break;
  }
  case STRING: {
    char *strKey = (char *)key;
    for (int i = 0; strKey[i] != '\0'; i++) {
      hashValue = (hashValue * 31) + strKey[i];
    }
    break;
  }
  case KVP: {
    KeyValuePair *kvp = (KeyValuePair *)key;
    hashValue = hash(hm, kvp->key.data);
    break;
  }
  }

  return hashValue % TABLE_SIZE;
}

HashMap *hmap_create(DataType key_type, DataType val_type) {
  HashMap *hm = malloc(sizeof(HashMap));
  hm->key_type = key_type;
  hm->val_type = val_type;
  for (int i = 0; i < TABLE_SIZE; i++) {
    hm->table[i] = llist_create(3);
  }
  return hm;
}

void hmap_put(HashMap *hm, void *key, void *value) {
  unsigned int idx = hash(hm, key);
  LinkedList *list = hm->table[idx];
  Node *current = list->head;

  KeyValuePair kv;
  kv.key.data = key;
  kv.key.type = hm->key_type;
  kv.value.data = value;
  kv.value.type = hm->val_type;
  // TODO: add checks to ensure type safety
  while (current != NULL) {
    KeyValuePair *current_kv = (KeyValuePair *)current->data.data;
    if (list->compareFunc(current_kv->key.data, key) == 0) {
      // Key already exists, update value
      current_kv->value.data = value;
      current_kv->value.type = hm->val_type;
      return;
    }
    current = current->next;
  }
  // Key doesn't exist, append the new key-value pair
  llist_append(list, &kv);
}

void *hmap_get(HashMap *hm, void *key) {
  unsigned int idx = hash(hm, key);
  LinkedList *list = hm->table[idx];
  Node *current = list->head;

  KeyValuePair kvToFind;
  kvToFind.key.type = hm->key_type;
  kvToFind.key.data = key;

  while (current != NULL) {
    KeyValuePair *kv = (KeyValuePair *)current->data.data;
    if (list->compareFunc(&kvToFind, kv) == 0) {
      return kv->value.data;
    }
    current = current->next;
  }

  return NULL; // Key not found
}

void hmap_print(HashMap *hm) {
  printf("HashMap {key: value}: {");
  int isFirstElement = 1;
  for (int i = 0; i < TABLE_SIZE; i++) {
    if (hm->table[i] && hm->table[i]->head) {
      Node *current = hm->table[i]->head;
      while (current) {
        KeyValuePair *kv = (KeyValuePair *)current->data.data;
        if (!isFirstElement) {
          printf(", ");
        }
        hm->table[i]->printFunc(kv);
        isFirstElement = 0;
        current = current->next;
      }
    }
  }
  printf("}\n");
}

void hmap_free(HashMap *hm) {
  for (int i = 0; i < TABLE_SIZE; i++) {
    llist_free(hm->table[i]);
  }
  free(hm);
}
