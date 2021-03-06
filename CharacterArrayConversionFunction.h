//
// Created by cornelius on 5/5/19.
//

#include <cctype>
#include <vector>

using std::vector;

char* convertCharacterArrayDataCStyle(char* inputCharArray, int numberOfInputChars)
{
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
    
    // create an output array with enough room for '\0' terminator-char.
    auto outputCharArray = static_cast<char*>(std::malloc(numberOfInputChars * sizeof(char) + 1));
    
    // copy the input contents to the output array.
    strcpy(outputCharArray, inputCharArray);
    
    int currentCharIndex = 0;
    
    // for each character in the array (except the null terminator)...
    while (currentCharIndex < numberOfInputChars)
    {
        if (!isalnum(inputCharArray[currentCharIndex]))
        {
            // character is non-alphanumeric.
            outputCharArray[currentCharIndex] = '.';
        }
        else if (islower(inputCharArray[currentCharIndex]))
        {
            // character is lowercase.
            outputCharArray[currentCharIndex] = toupper(inputCharArray[currentCharIndex]);
        }
        
        ++currentCharIndex;
    }
    
    // null-terminate the string.
    outputCharArray[currentCharIndex] = '\0';

    return outputCharArray;
}