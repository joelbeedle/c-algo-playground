// Guards to prevent multiple inclusion
#ifndef DATA_TYPES_H
#define DATA_TYPES_H

// Enum to define the supported data types
typedef enum { INT, FLOAT, STRING/*, other types as needed */ } DataType;

// Container for the data, associating a type with the generic data pointer
typedef struct {
    DataType type;
    void *data;
} DataContainer;

// Function declarations related to data types
// Printing Functions
void printInt(void* data);
void printFloat(void* data);
void printString(void* data);

// Comparing Functions
int compareInts(void* a, void* b);
int compareFloats(void* a, void* b);
int compareStrings(void* a, void* b);

#endif //DATA_TYPES_H