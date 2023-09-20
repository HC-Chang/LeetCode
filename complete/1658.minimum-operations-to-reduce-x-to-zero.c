/*
 * @lc app=leetcode id=1658 lang=c
 *
 * [1658] Minimum Operations to Reduce X to Zero
 */

// @lc code=start
int minOperations(int *nums, int numsSize, int x)
{
    x = -x;
    for (int i = 0; i < numsSize; i++)
        x += nums[i];

    if (x == 0)
        return numsSize;

    int max_len = 0;
    int cur_sum = 0;
    int left = 0;

    for (int right = 0; right < numsSize; ++right)
    {
        cur_sum += nums[right];
        while (left <= right && cur_sum > x)
        {
            cur_sum -= nums[left];
            left++;
        }
        if (cur_sum == x)
            max_len = fmax(max_len, right - left + 1);
    }

    return max_len ? numsSize - max_len : -1;
}
// @lc code=end

// Note: sliding window