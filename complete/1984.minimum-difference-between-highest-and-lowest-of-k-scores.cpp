/*
 * @lc app=leetcode id=1984 lang=cpp
 *
 * [1984] Minimum Difference Between Highest and Lowest of K Scores
 */

// @lc code=start
class Solution
{
public:
    int minimumDifference(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n < k)
            return 0;
        sort(nums.begin(), nums.end());
        int r = INT_MAX;
        for (int i = 0; i <= n - k; i++)
            r = min(nums[i + k - 1] - nums[i], r);
        return r;
    }
};
// @lc code=end
