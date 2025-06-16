/*
 * @lc app=leetcode id=2016 lang=cpp
 *
 * [2016] Maximum Difference Between Increasing Elements
 */

// @lc code=start
class Solution
{
public:
    int maximumDifference(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> max_arr(n);
        vector<int> min_arr(n);
        max_arr[n - 1] = nums[n - 1];
        min_arr[0] = nums[0];
        for (int i = n - 2; i >= 0; i--)
            max_arr[i] = max(max_arr[i + 1], nums[i]);
        for (int i = 1; i < n; i++)
            min_arr[i] = min(min_arr[i - 1], nums[i]);
        int max_val = 0;
        for (int i = 0; i < n; i++)
            max_val = max(max_arr[i] - min_arr[i], max_val);
        if (max_val == 0)
            return -1;
        return max_val;
    }
};
// @lc code=end
