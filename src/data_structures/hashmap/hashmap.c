#include "hashmap.h"

unsigned static int hash(HashMap* hm, void* key) {
    unsigned int hashValue = 0;

    switch(hm->key_type) {
        case INT: {
            int* intKey = (int*)key;
            hashValue = *intKey;
            break;
        }
        case FLOAT: {
            unsigned int int_representation;
            memcpy(&int_representation, &key, sizeof(float));
            float* floatKey = (float*)key;
            hashValue = int_representation;
            break;
        }
        case STRING: {
            char* strKey = (char*) key;
            for (int i = 0; strKey[i] != '\0'; i++) {
                hashValue = (hashValue * 31) + strKey[i];
            }
            break;
        }
    }

    return hashValue % TABLE_SIZE;
}

HashMap* create_hmap(DataType key_type, DataType val_type) {
    HashMap* hm = malloc(sizeof(HashMap));
    hm->key_type = key_type;
    hm-> val_type = val_type;
    for (int i = 0; i < TABLE_SIZE; i++) {
        hm->table[i] = llist_create(val_type);
    }
    return hm;
}

void hmap_put(HashMap* hm, void* key, void* value) {
    unsigned int idx = hash(hm, key);
    KeyValuePair kv;
    kv.key.data = key;
    kv.key.type = hm->key_type;
    kv.value.data = value;
    kv.value.type = hm->val_type;
    // TODO: add checks to ensure type safety
    llist_append(hm->table[idx], &kv);
}

void* hmap_get(HashMap* hm, void* key) {
    unsigned int idx = hash(hm, key);
    Node* current = hm->table[idx]->head;
    while (current != NULL) {
        void* value = current->data.data;
        if (hm->table[idx]->compareFunc())
    }
}