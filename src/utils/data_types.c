#include "utils/data_types.h"
#include <stdio.h>

// Implementation of functions declared in DataTypes.h

void printInt(void* data) {
    // Ensure data is not NULL before dereferencing it
    if (data) {
        printf("%d", *(int*)data);
    }
}

void printFloat(void* data) {
    // Ensure data is not NULL before dereferencing it
    if (data) {
        printf("%f", *(float*)data);
    }
}

void printString(void* data) {
    if (data) {
        printf("%s", (char*)data);
    }
}

void printKVP(void* data) {
    KeyValuePair* kvp = (KeyValuePair*)data;
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
    switch(kvp->value.type) {
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

int compareInts(void* a, void* b) {
    // Before comparing, ensure pointers are not NULL to avoid dereferencing NULL pointers
    if (!a || !b) return 0; // Or handle the error as suitable for your application

    int intA = *(int*)a;
    int intB = *(int*)b;
    return intA - intB; // 0 if equal, >0 if a is greater, <0 if b is greater
}

int compareFloats(void* a, void* b) {
    // Before comparing, ensure pointers are not NULL to avoid dereferencing NULL pointers
    if (!a || !b) return 0; // Or handle the error as suitable for your application

    float floatA = *(float*)a;
    float floatB = *(float*)b;
    if (floatA == floatB) return 0;
    return floatA > floatB ? 1 : -1;
}

int compareStrings(void* a, void* b) {
    // Before comparing, ensure pointers are not NULL to avoid dereferencing NULL pointers
    if (!a || !b) return 0; // Or handle the error as suitable for your application

    return strcmp((char*)a, (char*)b);
}

int compareKVP(void* a, void* b) {
    // Before comparing, ensure pointers are not NULL to avoid dereferencing NULL pointers
    if (!a || !b) return 0;


    KeyValuePair* kvpA = (KeyValuePair*)a;
    KeyValuePair* kvpB = (KeyValuePair*)b;
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