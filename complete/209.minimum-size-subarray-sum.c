/*
 * @lc app=leetcode id=209 lang=c
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
// Solution 2:
int minSubArrayLen(int target, int *nums, int numsSize)
{
    int left = 0, right = 0;
    int tmp = 0;
    int min_count = INT_MAX;
    while (right < numsSize)
    {
        tmp += nums[right++];
        while (tmp - nums[left] >= target)
            tmp -= nums[left++];

        if (tmp >= target && right - left < min_count)
            min_count = right - left;
    }
    if (min_count == INT_MAX)
        min_count = 0;
    return min_count;
}
// @lc code=end

// Note: Sliding Window

// Solution 1:
int minSubArrayLen(int target, int *nums, int numsSize)
{
    int left = 0, right = 0;
    int tmp = 0;
    int min_count = INT_MAX;
    while (right < numsSize)
    {
        tmp += nums[right++];
        while (tmp >= target)
        {
            if (tmp >= target && right - left < min_count)
                min_count = right - left;
            tmp -= nums[left++];
        }
    }
    if (min_count == INT_MAX)
        return 0;
    return min_count;
}