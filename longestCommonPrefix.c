#include <stdio.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if(strsSize == 0) return "";

    for(int i = 0; strs[0][i] != '\0' ; i++)
    {
        char c = strs[0][i];
    

    for(int j = 1; j < strsSize != '\0'; j++)
    {
        if(strs[j][i] != c)
        {
            strs[0][i] = '\0';
            return strs[0];
        }
    }
    }

    return strs[0];

}

int main(void)
{
    int size;
    printf("Enter number of strings: ");
    scanf("%d", &size);
    getchar();

    char* str[size];
    for(int i = 0; i < size; i++)
    {
        str[i] = malloc(50);
        printf("Enter the string %d: ",i+1);
        fgets(str[i],50,stdin);
    }

    char* prefix = longestCommonPrefix(str, size);
    printf("Longest common prefix: %s\n", prefix);

    for(int i = 0; i < size; i++)
    {
        free(str[i]);
    }

    return 0;

}