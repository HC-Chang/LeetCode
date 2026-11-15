/*
 * @lc app=leetcode id=3364 lang=c
 *
 * [3364] Minimum Positive Sum Subarray
 */

// @lc code=start
int minimumSumSubarray(int *nums, int numsSize, int l, int r)
{
    int prefix_sum[numsSize];
    prefix_sum[0] = nums[0];
    for (int i = 1; i < numsSize; i++)
        prefix_sum[i] = prefix_sum[i - 1] + nums[i];
    int min = INT_MAX;
    for (int ll = 0; ll <= numsSize - l; ll++)
    {
        for (int rr = ll + l - 1; rr < numsSize && rr - ll + 1 <= r; rr++)
        {
            int tmp = prefix_sum[rr] - prefix_sum[ll] + nums[ll];
            if (tmp > 0 && tmp < min)
                min = tmp;
        }
    }

    return min == INT_MAX ? -1 : min;
}
// @lc code=end

// Note: prefix sum