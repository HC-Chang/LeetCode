/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int left = 0, right = 0;
        int tmp = 0;
        int min_count = INT_MAX;
        int n = nums.size();
        while (right < n)
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
};
// @lc code=end

// Note: Sliding Window
