/*
 * @lc app=leetcode id=442 lang=c
 *
 * [442] Find All Duplicates in an Array
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findDuplicates(int *nums, int numsSize, int *returnSize)
{
    int hash[numsSize + 1];
    memset(hash, 0, sizeof(hash));

    *returnSize = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (++hash[nums[i]] == 2)
            nums[(*returnSize)++] = nums[i];
    }
    return nums;
}
// @lc code=end

// Note: hash table