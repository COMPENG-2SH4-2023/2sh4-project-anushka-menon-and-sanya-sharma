#include "objPosArrayList.h"
#include <iostream> // Include necessary headers


// Paste your CUTE Tested implementation here.
// Paste your CUTE Tested implementation here.
// Paste your CUTE Tested implementation here.

objPosArrayList::objPosArrayList(){ //array list constructor 
    
    sizeList = 0;
    sizeArray = ARRAY_MAX_CAP;
    aList = new objPos[sizeArray];
}


objPosArrayList::~objPosArrayList()  //array list destructor 
{
    delete[] aList;
}

int objPosArrayList::getSize() //returns the size of the list 
{
    return sizeList;
}


void objPosArrayList::insertHead(objPos thisPos) //method (insertHead) within a class (objPosArrayList). It inserts an element (thisPos) at the beginning of an array (aList) of objects of type objPos if space is available in the array. It shifts existing elements to accommodate the new element and increments the size of the list. However, it lacks the implementation for resizing the array if it's already full.
{
    if (sizeList < sizeArray) {
        for (int i = sizeList; i > 0; --i) { // element shift for head
            aList[i] = aList[i - 1];
        }
        aList[0] = thisPos;
        ++sizeList;
    }
    // case where the array is full, and resizing is needed
}

void objPosArrayList::insertTail(objPos thisPos){// inserting thisPos as a new objPos element to the tail of the list 
    
    if (sizeList < sizeArray) {
            aList[sizeList] = thisPos;
            ++sizeList;
        }
        // case where the array is full, and resizing is needed

}

void objPosArrayList::removeHead()  //remove the head from the element from the list 
{
    if (sizeList > 0) {
        for (int i = 0; i < sizeList - 1; ++i) {
            aList[i] = aList[i + 1];
        }
        --sizeList;
    }
}

void objPosArrayList::removeTail() //remove the tail element 
{
    if (sizeList > 0) {
        --sizeList;
    }
}

void objPosArrayList::getHeadElement(objPos &returnPos) //get the objPos element at the head of the list
{
    if (sizeList > 0) {
        returnPos = aList[0];
    }
}

void objPosArrayList::getTailElement(objPos &returnPos) //get the objPos element at the tail of the list
{
    if (sizeList > 0) {
        returnPos = aList[sizeList - 1];
    }
}

void objPosArrayList::getElement(objPos &returnPos, int index) //get the nth objpos element from the list, where n is specified by the index 
{
    if (index >= 0 && index < sizeList) {
        returnPos = aList[index];
    }
    // case where the index is out of bounds
}

