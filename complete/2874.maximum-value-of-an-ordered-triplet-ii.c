/*
 * @lc app=leetcode id=2874 lang=c
 *
 * [2874] Maximum Value of an Ordered Triplet II
 */

// @lc code=start
long long maximumTripletValue(int *nums, int numsSize)
{
    long long max_val = 0, imax = 0, diff = 0;
    for (int i = 0; i < numsSize; i++)
    {
        max_val = fmax(max_val, diff * nums[i]);
        diff = fmax(diff, imax - nums[i]);
        imax = fmax(imax, nums[i]);
    }
    return max_val;
}
// @lc code=end
