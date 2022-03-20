/*
 * @lc app=leetcode id=905 lang=c
 *
 * [905] Sort Array By Parity
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *sortArrayByParity(int *nums, int numsSize, int *returnSize)
{
    *returnSize = numsSize;
    int *r_array = calloc(numsSize ,sizeof(int));
    int left = 0;
    int right = numsSize - 1;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] % 2 == 0)
        {
            *(r_array + left) = nums[i];
            left++;
        }
        else
        {
            *(r_array + right) = nums[i];
            right--;
        }
    }

    return r_array;
}
// @lc code=end
