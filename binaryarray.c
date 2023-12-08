/*Write a program in C to create a binary array that supports three key operations: insert, get, and
delete a bit. The maximum memory wastage is 7 bits for all. You are supposed to use 1 bit for
1 bit memory location.*/


#include <stdio.h>
#include <stdlib.h>

// Define a structure for the binary array
typedef struct {
    unsigned char *data;  // Array to store bits
    int size;             // Size of the array in bits
} BinaryArray;

// Function to initialize a binary array with a given size
BinaryArray* initializeBinaryArray(int size) {
    BinaryArray* binaryArray = (BinaryArray*)malloc(sizeof(BinaryArray));
    binaryArray->size = size;
    binaryArray->data = (unsigned char*)malloc((size + 7) / 8); // Allocate memory for the array

    // Initialize all bits to 0
    for (int i = 0; i < (size + 7) / 8; i++) {
        binaryArray->data[i] = 0;
    }

    return binaryArray;
}

// Function to insert a bit at a given position
void insertBit(BinaryArray* binaryArray, int position, int bitValue) {
    if (position < 0 || position >= binaryArray->size) {
        printf("Error: Invalid position for insertion\n");
        return;
    }

    // Calculate the byte index and bit offset within that byte
    int byteIndex = position / 8;
    int bitOffset = position % 8;

    // Set or clear the bit based on the bitValue
    if (bitValue) {
        binaryArray->data[byteIndex] |= (1 << bitOffset); // Set the bit
    } else {
        binaryArray->data[byteIndex] &= ~(1 << bitOffset); // Clear the bit
    }
}

// Function to get the value of a bit at a given position
int getBit(BinaryArray* binaryArray, int position) {
    if (position < 0 || position >= binaryArray->size) {
        printf("Error: Invalid position for get operation\n");
        return -1; // Error code for invalid position
    }

    // Calculate the byte index and bit offset within that byte
    int byteIndex = position / 8;
    int bitOffset = position % 8;

    // Get the value of the bit at the specified position
    return (binaryArray->data[byteIndex] >> bitOffset) & 1;
}

// Function to delete a bit at a given position
void deleteBit(BinaryArray* binaryArray, int position) {
    insertBit(binaryArray, position, 0); // Set the bit to 0 to delete it
}

// Function to free the memory allocated for the binary array
void freeBinaryArray(BinaryArray* binaryArray) {
    free(binaryArray->data);
    free(binaryArray);
}

// Example usage
int main() {
    int size = 20; // Example size of the binary array

    // Initialize a binary array
    BinaryArray* binaryArray = initializeBinaryArray(size);

    // Insert some bits
    insertBit(binaryArray, 2, 1);
    insertBit(binaryArray, 5, 1);
    insertBit(binaryArray, 10, 0);

    // Get and print the values of some bits
    printf("Bit at position 2: %d\n", getBit(binaryArray, 2));
    printf("Bit at position 5: %d\n", getBit(binaryArray, 5));
    printf("Bit at position 10: %d\n", getBit(binaryArray, 10));

    // Delete a bit at position 5
    deleteBit(binaryArray, 5);

    // Get and print the new value of the bit at position 5
    printf("Bit at position 5 after deletion: %d\n", getBit(binaryArray, 5));

    // Free the memory allocated for the binary array
    freeBinaryArray(binaryArray);

    return 0;
}