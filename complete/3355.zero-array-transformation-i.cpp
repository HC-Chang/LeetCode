/*
 * @lc app=leetcode id=3355 lang=cpp
 *
 * [3355] Zero Array Transformation I
 */

// @lc code=start
class Solution
{
public:
    bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        int d[n + 1];
        memset(d, 0, sizeof(d));
        for (const auto &q : queries)
        {
            ++d[q[0]];
            --d[q[1] + 1];
        }
        for (int i = 0, s = 0; i < n; ++i)
        {
            s += d[i];
            if (nums[i] > s)
                return false;
        }
        return true;
    }
};
// @lc code=end

// Note: prefix sum