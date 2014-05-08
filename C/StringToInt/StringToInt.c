#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int StringToInt(char *_strIn)
{
    if (_strIn == NULL) // Return 0 if null input as specified by document
    {
        return 0;
    }
    else
    {
        // Instantiate a pointer and traverse string to check for non-numeric characters
        char *p = _strIn;
        int nLen = strlen(_strIn);
        while (*p != '\0')
        {
            if (*p < 0x30 || *p > 0x39)
            {
                // Copy memory in place
                memcpy(p, p+1, nLen-(_strIn-p));
            }
            else
            {
                // Increment to the next character in the string
                p++;
            }
        }

        return atoi(_strIn);
    }

}

int main()
{
    printf(">>>Start\n");
    int nResult;

    nResult = StringToInt(NULL);
    printf("Result is: %d\n", nResult);

    char test1[] = "a1b2c3d4e5";
    nResult = StringToInt(test1);
    printf("Result is: %d\n", nResult);

    char test2[] = "aaaaa";
    nResult = StringToInt(test2);
    printf("Result is: %d\n", nResult);

    char test3[] = "1234567890";
    nResult = StringToInt(test3);
    printf("Result is: %d\n", nResult);

    char test4[] = "123aaa";
    nResult = StringToInt(test4);
    printf("Result is: %d\n", nResult);

    char test5[] = "";
    nResult = StringToInt(test5);
    printf("Result is: %d\n", nResult);
    printf("<<<End\n");

    return 1;
}
