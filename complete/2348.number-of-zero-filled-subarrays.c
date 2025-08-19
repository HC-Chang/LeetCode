/*
 * @lc app=leetcode id=2348 lang=c
 *
 * [2348] Number of Zero-Filled Subarrays
 */

// @lc code=start
long long sum_arr(unsigned int n) { return n * (n + 1) / 2; }
long long zeroFilledSubarray(int *nums, int numsSize)
{
    unsigned int total_count = 0;
    long long zero_count = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == 0)
            zero_count++;
        else if (zero_count != 0)
        {
            total_count += sum_arr(zero_count);
            zero_count = 0;
        }
    }
    if (zero_count != 0)
        total_count += sum_arr(zero_count);
    return total_count;
}
// @lc code=end

// Note: math