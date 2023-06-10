/*
 * @lc app=leetcode id=334 lang=c
 *
 * [334] Increasing Triplet Subsequence
 */

// @lc code=start
bool increasingTriplet(int *nums, int numsSize)
{
    int i1 = INT_MAX, i2 = INT_MAX;
    for (int i = 0; i < numsSize; i++)
    {
        if (i1 >= nums[i])
            i1 = nums[i];
        else if (i2 >= nums[i])
            i2 = nums[i];
        else
            return true;
    }
    return false;
}
// @lc code=end
