#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* returnSize) 
{
    int numsSize;
    printf("Enter the size of the array: ");
    scanf("%d", &numsSize);

    int* nums = (int*)malloc(numsSize * sizeof(int));
    printf("Enter the elements of the array: ");
    for (int i = 0; i < numsSize; i++) {
        scanf("%d", &nums[i]);
    }

    int target;
    printf("Enter the target sum: ");
    scanf("%d", &target);


    for(int i = 0; i < numsSize; i++)
    {
        for(int j = i + 1; j < numsSize; j++)
        {
            if(nums[i] + nums[j] == target)
            {
                printf("Indices found: [%d, %d]\n", i, j);
                returnSize[0] = i;
                returnSize[1] = j;
                return returnSize;
            }
            else
            {
            printf("No valid pair found.\n");

            }
        }
    }

    free(nums);
    return NULL;
}


int main()
{

    
    int* returnSize = twoSum(returnSize);
    return 0;

}