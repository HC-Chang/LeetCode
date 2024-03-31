/*
 * @lc app=leetcode id=2444 lang=cpp
 *
 * [2444] Count Subarrays With Fixed Bounds
 */

// @lc code=start
class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        long long count = 0;
        int prev_min = -1, prev_max = -1, boundary = -1;
        int tmp;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < minK || nums[i] > maxK)
            {
                boundary = i;
                continue;
            }

            if (nums[i] == minK)
                prev_min = i;
            if (nums[i] == maxK)
                prev_max = i;
            tmp = min(prev_min, prev_max) - boundary;
            if (tmp > 0)
                count += tmp;
        }

        return count;
    }
};
// @lc code=end
