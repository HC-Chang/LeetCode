/*
 * @lc app=leetcode id=287 lang=c
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
int findDuplicate(int *nums, int numsSize)
{
    int hash[numsSize];
    memset(hash, 0, numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++)
    {
        if (hash[nums[i]]++ >= 1)
            return nums[i];
    }
    return nums[numsSize - 1];
}
// @lc code=end
