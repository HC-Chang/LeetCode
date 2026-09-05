/*
 * @lc app=leetcode id=3904 lang=cpp
 *
 * [3904] Smallest Stable Index II
 */

// @lc code=start
class Solution
{
public:
    int firstStableIndex(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> min_arr(n);
        min_arr[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            min_arr[i] = min(min_arr[i + 1], nums[i]);

        int max_val = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > max_val)
                max_val = nums[i];
            if (max_val - min_arr[i] <= k)
                return i;
        }

        return -1;
    }
};
// @lc code=end

// Note: prefix sum