/*
 * @lc app=leetcode id=1980 lang=cpp
 *
 * [1980] Find Unique Binary String
 */

// @lc code=start
class Solution
{
public:
    string findDifferentBinaryString(vector<string> &nums)
    {
        int n = nums.size();
        string r(n, '0');
        for (int i = 0; i < n; ++i)
            r[i] = '1' - nums[i][i] + '0';
        return r;
    }
};
// @lc code=end
