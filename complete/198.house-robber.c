/*
 * @lc app=leetcode id=198 lang=c
 *
 * [198] House Robber
 */

// @lc code=start
int rob(int *nums, int numsSize)
{
    if (numsSize == 0)
        return 0;
    if (numsSize == 1)
        return nums[0];
    if (numsSize == 2)
        return fmax(nums[0], nums[1]);

    if (nums[0] > nums[1])
        nums[1] = nums[0];
    for (int i = 2; i < numsSize; i++)
        nums[i] = fmax(nums[i - 2] + nums[i], nums[i - 1]);

    return nums[numsSize - 1];
}
// @lc code=end

// Note: DP