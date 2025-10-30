#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool ispalindrome(int x)
{
    //count digits
    if (x < 0) return false;
    int temp = x, count = 0;
    while(temp > 0)
    {
        count++;
        temp /= 10;
    }

    //create array to hold each digit
    int *arr = malloc(count*sizeof(int));
    
    temp = x;
    //fill array
    for(int i = 0; i < count; i++)
    {
        int j = i + 1;
        arr[count-j] = temp % 10;
        temp /= 10;
    }
    //print array
    for(int i = 0; i < count; i++)
    {
        printf("%d",arr[i]);
    }

    printf("\n");
    int temp2 = x;

    for(int i = 0; i < count; i++)
    {
        if (arr[i] == temp2 % 10)
        {
            temp2 /= 10;
        }
        else
        {
            printf("Not a palindrome.\n", x);
            free(arr);
            return 0;
        }
    }
    printf("%d reads from right to left and is a palindrome\n", x);
    free(arr);
    return 1;

}


int main()
{
    int x;
    printf("Enter the number: ");
    scanf("%d",&x);
    ispalindrome(x);

    return 0;

}