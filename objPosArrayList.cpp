#include "objPosArrayList.h"

// Paste your CUTE Tested implementation here.
// Paste your CUTE Tested implementation here.
// Paste your CUTE Tested implementation here.

// Default constructor for objPosArrayList
objPosArrayList::objPosArrayList() 
{
    sizeList = 0;               // Initialize the size of the list to 0
    sizeArray = ARRAY_MAX_CAP;  // Set the maximum capacity of the array list
    aList = new objPos[sizeArray];  // Allocate memory for the array list
}

// Destructor for objPosArrayList
objPosArrayList::~objPosArrayList() 
{
    delete[] aList;  // Deallocate memory used by the array list
}

// Get the current size of the array list
int objPosArrayList::getSize() 
{
    return sizeList;  // Return the current size of the list
}

// Insert an element at the head of the array list
void objPosArrayList::insertHead(objPos thisPos) 
{
    if (sizeList < sizeArray) {
        for (int i = sizeList; i > 0; --i) { // Shift elements to make space for the new element at the head
            aList[i] = aList[i - 1];
        }
        aList[0] = thisPos; // Insert the new element at the head
        ++sizeList; // Increment the size of the list
    }
    // Additional handling for cases where the array is full and resizing is needed could be added here
}

// Insert an element at the tail of the array list
void objPosArrayList::insertTail(objPos thisPos) 
{
    if (sizeList < sizeArray) {
        aList[sizeList] = thisPos; // Insert the new element at the tail
        ++sizeList; // Increment the size of the list
    }
    // Additional handling for cases where the array is full and resizing is needed could be added here
}

// Remove the element at the head of the array list
void objPosArrayList::removeHead() 
{
    if (sizeList > 0) {
        for (int i = 0; i < sizeList - 1; ++i) { // Shift elements to remove the element at the head
            aList[i] = aList[i + 1];
        }
        --sizeList; // Decrement the size of the list
    }
}

// Remove the element at the tail of the array list
void objPosArrayList::removeTail() 
{
    if (sizeList > 0) {
        --sizeList; // Decrement the size of the list
    }
}

// Get the element at the head of the array list
void objPosArrayList::getHeadElement(objPos &returnPos) 
{
    if (sizeList > 0) {
        returnPos = aList[0]; // Get the element at the head
    }
}

// Get the element at the tail of the array list
void objPosArrayList::getTailElement(objPos &returnPos) 
{
    if (sizeList > 0) {
        returnPos = aList[sizeList - 1]; // Get the element at the tail
    }
}

// Get the element at a specific index in the array list
void objPosArrayList::getElement(objPos &returnPos, int index) 
{
    if (index >= 0 && index < sizeList) {
        returnPos = aList[index]; // Get the element at the specified index
    }
    // Additional handling for cases where the index is out of bounds could be added here
}
