#ifndef OBJPOS_ARRAYLIST_H
#define OBJPOS_ARRAYLIST_H

#define ARRAY_MAX_CAP 200 // Maximum capacity of the array list

#include "objPos.h" // Include the definition of objPos class

class objPosArrayList
{
private:
    objPos* aList;   // Pointer to an array of objPos objects
    int sizeList;    // Current size of the array list
    int sizeArray;   // Maximum capacity of the array list

public:
    // Constructor and Destructor
    objPosArrayList();  // Default constructor
    ~objPosArrayList(); // Destructor

    // Methods for managing the array list
    int getSize();                  // Get the current size of the array list
    void insertHead(objPos thisPos);// Insert an element at the head of the array list
    void insertTail(objPos thisPos);// Insert an element at the tail of the array list
    void removeHead();              // Remove an element from the head of the array list
    void removeTail();              // Remove an element from the tail of the array list
    void getHeadElement(objPos &returnPos); // Get the element at the head of the array list
    void getTailElement(objPos &returnPos); // Get the element at the tail of the array list
    void getElement(objPos &returnPos, int index); // Get the element at a specified index in the array list
};

#endif // OBJPOS_ARRAYLIST_H
