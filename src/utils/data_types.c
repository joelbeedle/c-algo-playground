#include "data_types.h"
#include <stdio.h>

// Implementation of functions declared in DataTypes.h

void printInt(void* data) {
    // Ensure data is not NULL before dereferencing it
    if (data) {
        printf("%d ", *(int*)data);
    }
}

void printFloat(void* data) {
    // Ensure data is not NULL before dereferencing it
    if (data) {
        printf("%f ", *(float*)data);
    }
}

void printString(void* data) {
    if (data) {
        printf("%s", (char*)data);
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