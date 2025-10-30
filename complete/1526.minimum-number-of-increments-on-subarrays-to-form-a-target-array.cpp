/*
 * @lc app=leetcode id=1526 lang=cpp
 *
 * [1526] Minimum Number of Increments on Subarrays to Form a Target Array
 */

// @lc code=start
class Solution
{
public:
    int minNumberOperations(vector<int> &target)
    {
        int n = target.size();
        int ans = target[0];
        for (int i = 1; i < n; ++i)
            ans += max(target[i] - target[i - 1], 0);
        return ans;
    }
};
// @lc code=end

// Note: DP + stack + greedy + monotonic stack

// Official Solution