#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdio.h>
#include <stdlib.h>

#include "utils/data_types.h"
#include "data_structures/linked_list/llist.h"

#define TABLE_SIZE 1000

typedef struct KeyValuePair {
    DataContainer key;
    DataContainer value;
} KeyValuePair;

typedef struct HashMap {
    LinkedList* table[TABLE_SIZE];
    DataType key_type;
    DataType val_type;
} HashMap;

unsigned static int hash(HashMap* hm, void* key);
HashMap* hmap_create(DataType key_type, DataType val_type);
void hmap_put(HashMap* hm, void* key, void* value);
void* hmap_get(HashMap* hm, void* key);
void hmap_free(HashMap* hm);

#endif // HASHMAP_H