/*
 * @lc app=leetcode id=1 lang=c
 *
 * [1] Two Sum
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int i, j;
    *returnSize = 2;
    int *returnArray = malloc(2 * sizeof(int));

    for (i = 0; i < numsSize; i++)
    {
        for (j = i + 1; j < numsSize; j++)
        {
            if ((nums[i] + nums[j]) == target)
            {
                returnArray[0] = i;
                returnArray[1] = j;
                break;
            }
        }
    }

    return returnArray;
}
// @lc code=end
