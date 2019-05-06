//
// Created by cornelius on 5/5/19.
//

#include <gtest/gtest.h>
#include "CharacterArrayConversionFunction.h"

TEST(test_cstyle_input_char_array, empty_array)
{
    char* emptyCharArray = nullptr;
    int testNumberOfChars = 5;
    
    char* outputCharArray = convertCharacterArrayDataCStyle(emptyCharArray, testNumberOfChars);
    
    EXPECT_EQ(outputCharArray, nullptr);
}

TEST(test_cstyle_number_of_input_chars, negative_count)
{
    char* testCharArray = "test phrase";
    int testNumberOfChars = -9;
    
    char* outputCharArray = convertCharacterArrayDataCStyle(testCharArray, testNumberOfChars);
    
    EXPECT_EQ(outputCharArray, testCharArray);
}

TEST(test_cstyle_number_of_input_chars, zero_count)
{
    char* testCharArray = "another test phrase";
    int testNumberOfChars = 0;
    
    char* outputCharArray = convertCharacterArrayDataCStyle(testCharArray, testNumberOfChars);
    
    EXPECT_EQ(outputCharArray, testCharArray);
}

TEST(test_cstyle_number_of_input_chars, positive_count)
{
    char testCharArray[] = "third test___phrase";
    int testNumberOfChars = 20;
    
    char* outputCharArray = convertCharacterArrayDataCStyle(testCharArray, testNumberOfChars);
    
    std::cout << "test input array:  ___" << testCharArray << "___" << std::endl;
    std::cout << "test output array: ___" << outputCharArray << "___" << std::endl;
    
    EXPECT_EQ(outputCharArray, "THIRD.TEST...PHRASE");
}

TEST(test_cpp_style_input_char_array, empty_array)
{
    char* emptyCharArray = nullptr;
    int testNumberOfChars = 5;
    
    char* outputCharArray = convertCharacterArrayDataCppStyle(emptyCharArray, testNumberOfChars);
    
    EXPECT_EQ(outputCharArray, nullptr);
}

TEST(test_cpp_style_number_of_input_chars, negative_count)
{
    char* testCharArray = "test phrase";
    int testNumberOfChars = -9;
    
    char* outputCharArray = convertCharacterArrayDataCppStyle(testCharArray, testNumberOfChars);
    
    EXPECT_EQ(outputCharArray, testCharArray);
}

TEST(test_cpp_style_number_of_input_chars, zero_count)
{
    char* testCharArray = "another test phrase";
    int testNumberOfChars = 0;
    
    char* outputCharArray = convertCharacterArrayDataCppStyle(testCharArray, testNumberOfChars);
    
    EXPECT_EQ(outputCharArray, testCharArray);
}

TEST(test_cpp_style_number_of_input_chars, positive_count)
{
    char testCharArray[] = "third test___phrase";
    int testNumberOfChars = 20;
    
    char* outputCharArray = convertCharacterArrayDataCppStyle(testCharArray, testNumberOfChars);
    
    std::cout << "test input array:  ___" << testCharArray << "___" << std::endl;
    std::cout << "test output array: ___" << outputCharArray << "___" << std::endl;
    
    EXPECT_EQ(outputCharArray, "THIRD.TEST...PHRASE");
}

TEST(test_is_alnum, alpha_char_lowercase)
{
    char testA = 'a';
    
    EXPECT_TRUE(isalnum(testA));
}

TEST(test_is_alnum, alpha_char_uppercase)
{
    char test = 'Z';
    
    EXPECT_TRUE(isalnum(test));
}

TEST(test_is_alnum, numeric_char)
{
    char test = '9';
    
    EXPECT_TRUE(isalnum(test));
}

TEST(test_is_alnum, non_alpha_non_numeric_chars)
{
    char test = '_';
    EXPECT_FALSE(isalnum(test));
    
    test = '/';
    EXPECT_FALSE(isalnum(test));
    
    test = '.';
    EXPECT_FALSE(isalnum(test));
    
    test = ' ';
    EXPECT_FALSE(isalnum(test));
}

