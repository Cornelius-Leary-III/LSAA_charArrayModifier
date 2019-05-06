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
    char outputCharArray[numberOfInputChars + 1];
    
    // copy the input contents to the output array.
    strcpy(outputCharArray, inputCharArray);
    
    int currentCharIndex = 0;
    
    // for each character in the array (except the null terminator)...
    while (currentCharIndex < numberOfInputChars - 1)
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
        
        std::cout << "current character: ___" << outputCharArray[currentCharIndex]
                  << "___" << std::endl;
        
        ++currentCharIndex;
    }
    
    std::cout << "input array:  ___" << inputCharArray << "___" << std::endl;
    std::cout << "output array: ___" << outputCharArray << "___" << std::endl;
    
    inputCharArray = outputCharArray;
    
    std::cout << std::endl;
    std::cout << "input array:  ___" << inputCharArray << "___" << std::endl;
    std::cout << "output array: ___" << outputCharArray << "___" << std::endl;
    
    //    return outputCharArray;
    
    return inputCharArray;
}

char* convertCharacterArrayDataCppStyle(char* inputCharArray, int numberOfInputChars)
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
 
    // add each character into the vector.
    vector<char> outputChars;
    
    int charIndex = 0;
    while (charIndex < numberOfInputChars)
    {
        // determine current character type.
        if (!isalnum(inputCharArray[charIndex]))
        {
            // character is non-alphanumeric.
            outputChars.push_back('.');
        }
        else if (islower(inputCharArray[charIndex]))
        {
            // character is lowercase.
            outputChars.push_back(toupper(inputCharArray[charIndex]));
        }
        else
        {
            // character is already an UPPERCASE alpha character or numeric character.
            outputChars.push_back(inputCharArray[charIndex]);
        }
        
        ++charIndex;
    }
    
    char outputCharArray[outputChars.size() + 1];
    
    int outputCharIndex = 0;
    int outputCharsSize = outputChars.size();
    
    // create output character array.
    while (outputCharIndex < outputCharsSize)
    {
        outputCharArray[outputCharIndex] = outputChars[outputCharIndex];
        ++outputCharIndex;
    }
    
    inputCharArray = outputCharArray;
    return inputCharArray;
}