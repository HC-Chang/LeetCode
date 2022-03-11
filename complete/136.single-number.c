/*
 * @lc app=leetcode id=136 lang=c
 *
 * [136] Single Number
 */

// @lc code=start

int singleNumber(int *nums, int numsSize)
{
    int r = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        r ^= nums[i];
    }

    return r;
}
// @lc code=end
