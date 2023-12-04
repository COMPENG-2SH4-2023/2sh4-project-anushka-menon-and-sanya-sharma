#include "objPos.h" // Include the corresponding header file

// Default constructor initializes objPos with default values
objPos::objPos()
{
    x = 0; // Initialize x-coordinate to 0
    y = 0; // Initialize y-coordinate to 0
    symbol = 0; // Initialize symbol to NULL character
}

// Copy constructor copies values from another objPos object
objPos::objPos(objPos &o)
{
    x = o.x; // Copy x-coordinate from 'o'
    y = o.y; // Copy y-coordinate from 'o'
    symbol = o.symbol; // Copy symbol from 'o'
}

// Parameterized constructor initializes objPos with provided values
objPos::objPos(int xPos, int yPos, char sym)
{
    x = xPos; // Initialize x-coordinate with provided value
    y = yPos; // Initialize y-coordinate with provided value
    symbol = sym; // Initialize symbol with provided value
}

// Set objPos values from another objPos object
void objPos::setObjPos(objPos o)
{
    x = o.x; // Set x-coordinate from 'o'
    y = o.y; // Set y-coordinate from 'o'
    symbol = o.symbol; // Set symbol from 'o'
}

// Set objPos values with provided parameters
void objPos::setObjPos(int xPos, int yPos, char sym)
{
    x = xPos; // Set x-coordinate with provided value
    y = yPos; // Set y-coordinate with provided value
    symbol = sym; // Set symbol with provided value
}

// Get objPos values and store them in another objPos object
void objPos::getObjPos(objPos &returnPos)
{
    returnPos.setObjPos(x, y, symbol); // Store current objPos values in returnPos
}

// Get the symbol associated with objPos
char objPos::getSymbol()
{
    return symbol; // Return the symbol of objPos
}

// Check if the provided position is equal to objPos
bool objPos::isPosEqual(objPos* refPos)
{
    return (refPos->x == x && refPos->y == y); // Check if coordinates match
}

// Get the symbol if the provided position is equal to objPos
char objPos::getSymbolIfPosEqual(objPos* refPos)
{
    if(isPosEqual(refPos)) // Check if positions match
        return getSymbol(); // Return symbol if positions match
    else
        return 0; // Return NULL character if positions do not match
}
