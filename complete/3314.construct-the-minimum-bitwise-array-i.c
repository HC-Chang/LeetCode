/*
 * @lc app=leetcode id=3314 lang=c
 *
 * [3314] Construct the Minimum Bitwise Array I
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *minBitwiseArray(int *nums, int numsSize, int *returnSize)
{
    *returnSize = numsSize;
    int tmp;
    for (int i = 0; i < numsSize; i++)
    {
        tmp = -1;
        for (int j = nums[i] / 2; j < nums[i]; j++)
        {
            if ((j | (j + 1)) == nums[i])
            {
                tmp = j;
                break;
            }
        }
        nums[i] = tmp;
    }

    return nums;
}
// @lc code=end

// Note: bit manipulation