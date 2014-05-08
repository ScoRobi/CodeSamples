#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_WORDS 10

char *ReverseWordsInString(char *_strIn)
{
    // Initialize an array of integers to store index of spaces
    char *pSpace = (char*)malloc(NUM_WORDS * sizeof(char));
    memset(pSpace, 0, NUM_WORDS*sizeof(char));
    
    // Initialize variables to reallocate buffer size if needed
    int nSpaceCount = 0;
    int nBufferLen = NUM_WORDS;
    int nBufferBytes = NUM_WORDS * sizeof(char);
    
    // Reverse traverse through char array to find all spaces
    char *pSpaceItr = pSpace;
    for (char *p = _strIn + strlen(_strIn); p != _strIn; p--)
    {
        if (*p == ' ')
        {
            // Add index to dynamic array if current character is a space
            *pSpaceItr = p - _strIn;                            // Store the index of the space into buffer
            nSpaceCount++;                                      // Increment the count of spaces found + added to buffer
            
            if (nSpaceCount == nBufferLen)
            {
                // Reallocate space if/when needed
                nBufferLen+=NUM_WORDS;                          // Increment the length of the buffer
                nBufferBytes = nBufferBytes * 2;                // Increment the size of the buffer (grows exponentionally)
                pSpace = (char*)realloc(pSpace, nBufferBytes);  // Reallocate the array
                memset(pSpace+nSpaceCount, 0, NUM_WORDS-1);     // Set all new array entries to 0
                pSpaceItr = pSpace + nSpaceCount;               // Point the itr to the new memory location
            }
            else
            {
                // Point to the next available int in the array
                pSpaceItr++;
            }
        }
    }
    
    // Return word if there are no spaces in the input string
    if (nSpaceCount == 0)
    {
        return _strIn;  // NOTE: Could return a malloc char array here also if mutual exclusivity between input and output is desired
    }
    
    // Initialize the output string and itr
    long nLen = strlen(_strIn);
    char *strOut = malloc(nLen+1);
    *(strOut + nLen) = 0;
    char *strOutItr = strOut;

    // Handle first word
    memcpy(strOutItr, (_strIn + *pSpace + 1), (nLen - *pSpace - 1));    // Copy from the char after the last space to the end of the string
    strOutItr += (nLen - *pSpace - 1);                                  // Increment itr by the amount copied
    memset(strOutItr, ' ', 1);                                          // Add a space
    strOutItr++;                                                        // Increment itr by one to point to the char after the space
    
    pSpaceItr = pSpace + 1;
    if (nSpaceCount > 1)
    {
        // Handle middle words
        while (*pSpaceItr != 0) // Run until reach the end of the array
        {
            char *pWordBegin = _strIn + *pSpaceItr + 1;             // The beginning of the word is the char after the space
            int nCharToCopy = *(pSpaceItr-1) - *pSpaceItr - 1;      // Len of word is 1 less than difference of the prev array int minus the current array int
        
            memcpy(strOutItr, pWordBegin, nCharToCopy);             // Copy the word into the correct offset of the output buffer
            strOutItr += nCharToCopy;                               // Increment the current position in the buffer itr by # of chars added
        
            memset(strOutItr, ' ', 1);                              // Add a space
            strOutItr++;                                            // Increment the current position in the buffer itr by 1 to point to after space
            
            pSpaceItr++;                                            // Increment the current position in the offset buffer to point to offset of next space
        }
    }
    
    // Handle last word
    memcpy(strOutItr, _strIn, *(pSpaceItr-1));  // Copy from the beginning of inpuf buffer to index of first space
    
    // Free memory
    free(pSpace);
    
    return strOut;
}

int main()
{
    printf(">>>START\n");
    
    char *pResult = NULL;
    
    char test0[] = "this is a test";
    pResult = ReverseWordsInString(test0);
    printf("%s --> %s\n", test0, pResult);
    free(pResult);
    
    char test1[] = "OneWord";
    pResult = ReverseWordsInString(test1);
    printf("%s --> %s\n", test1, pResult);
    // NOTE: No need to free() since it returns a ptr to the input string
    
    char test2[] = "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15";
    pResult = ReverseWordsInString(test2);
    printf("%s --> %s\n", test2, pResult);
    free(pResult);
    
    char test3[] = "A     B   C";
    pResult = ReverseWordsInString(test3);
    printf("%s --> %s\n", test3, pResult);
    free(pResult);
    
    char test4[] = "Two Words";
    pResult = ReverseWordsInString(test4);
    printf("%s --> %s\n", test4, pResult);
    free(pResult);
    
    char test5[] = "Apply at Tenable Network Security";
    pResult = ReverseWordsInString(test5);
    printf("%s --> %s\n", test5, pResult);
    free(pResult);
    
    printf("<<<END\n");
    
    return 1;
}
