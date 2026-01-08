//@a.d.a.n_noa😇
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int lengthOfLongestSubstring(char* s)
{
    int last[256];
    for (int i = 0; i < 256; i++)
        last[i] = -1;

    int maxLen = 0;
    int start = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        unsigned char c = s[i]; //say c = A = 65

        if (last[c] >= start) //last[65] = -1, so if -1 >= 0
            start = last[c] + 1;

        last[c] = i; //last[65] = 0;

        int len = i - start + 1;
        if (len > maxLen)
            maxLen = len;
    }

    return maxLen;
}
/*
int lengthOfLongestSubstring(char* s)
{
    int last[256];               // Step 1: Array to remember last index of every character
    for (int i = 0; i < 256; i++)
        last[i] = -1;            // Step 2: Initialize all entries to -1 (haven’t seen any character yet)

    int maxLen = 0;              // Step 3: This will store the maximum length found
    int start = 0;               // Step 4: Start index of current substring without duplicates

    for (int i = 0; s[i] != '\0'; i++)  // Step 5: Loop over each character in the string
    {
        unsigned char c = s[i];  // Step 6: Get the character at position i, use as array index

        if (last[c] >= start)    // Step 7: Check if this character was seen in the current substring
            start = last[c] + 1; // Step 8: If yes, move start right after previous occurrence

        last[c] = i;             // Step 9: Update last seen index of this character

        int len = i - start + 1; // Step 10: Calculate length of current substring
        if (len > maxLen)        // Step 11: Update maxLen if current substring is longer
            maxLen = len;
    }

    return maxLen;               // Step 12: Return the length of the longest substring found
}
*/


int main()
{
    char s[50];
    printf("Enter string: ");
    fgets(s, 50, stdin);

    int length = lengthOfLongestSubstring(s);

    printf("Longest substring: %d.\n",length);

    return 0;

}