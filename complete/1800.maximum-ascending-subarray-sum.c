/*
 * @lc app=leetcode id=1800 lang=c
 *
 * [1800] Maximum Ascending Subarray Sum
 */

// @lc code=start
int maxAscendingSum(int *nums, int numsSize)
{
    if (numsSize == 1)
        return nums[0];
    else if (numsSize == 0)
        return 0;
    int tmp = nums[0];
    int max_sum = 0;
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] - nums[i - 1] > 0)
            tmp += nums[i];
        else
        {
            if (tmp > max_sum)
                max_sum = tmp;
            tmp = nums[i];
        }
    }
    if (tmp > max_sum)
        return tmp;
    return max_sum;
}
// @lc code=end
