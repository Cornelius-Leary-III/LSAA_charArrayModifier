//
// Created by cornelius on 5/5/19.
//

#include <cctype>

char* convertCharacterArrayData(char* inputCharArray, int numberOfInputChars)
{
    int currentCharIndex = 0;
    
    // check if input character array is empty.
    if (inputCharArray == nullptr)
    {
        return inputCharArray;
    }
    
    // check if the input character count is a positive integer.
    if (numberOfInputChars <= 0)
    {
        return inputCharArray;
    }
    
    // for each character in the array...
    while (currentCharIndex != numberOfInputChars)
    {
        if (!isalnum(inputCharArray[currentCharIndex]))
        {
            // character is non-alphanumeric.
            inputCharArray[currentCharIndex] = '.';
        }
        else if (islower(inputCharArray[currentCharIndex]))
        {
            // character is lowercase.
            inputCharArray[currentCharIndex] = toupper(inputCharArray[currentCharIndex]);
        }
        
        ++currentCharIndex;
    }
    
    return inputCharArray;
}