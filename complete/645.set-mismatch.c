/*
 * @lc app=leetcode id=645 lang=c
 *
 * [645] Set Mismatch
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findErrorNums(int *nums, int numsSize, int *returnSize)
{
    *returnSize = 2;
    int hash[numsSize + 1];
    memset(hash, 0, sizeof(hash));
    for (int i = 0; i < numsSize; i++)
        ++hash[nums[i]];
    for (int i = 1; i <= numsSize; i++)
    {
        if (hash[i] == 2)
            nums[0] = i;
        else if (hash[i] == 0)
            nums[1] = i;
    }

    return nums;
}
// @lc code=end

// Note: hash map
