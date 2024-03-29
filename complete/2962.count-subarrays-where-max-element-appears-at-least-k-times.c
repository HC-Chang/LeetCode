/*
 * @lc app=leetcode id=2962 lang=c
 *
 * [2962] Count Subarrays Where Max Element Appears at Least K Times
 */

// @lc code=start
long long countSubarrays(int *nums, int numsSize, int k)
{
    int max_val = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] > max_val)
            max_val = nums[i];
    }

    long long ans = 0;
    int cnt = 0, j = 0;
    for (int i = 0; i < numsSize; i++)
    {
        while (j < numsSize && cnt < k)
            cnt += nums[j++] == max_val;
        if (cnt < k)
            break;

        ans += numsSize - j + 1;
        cnt -= nums[i] == max_val;
    }
    return ans;
}
// @lc code=end

// Note: sliding window