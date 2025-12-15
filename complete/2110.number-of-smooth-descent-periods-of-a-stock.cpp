/*
 * @lc app=leetcode id=2110 lang=cpp
 *
 * [2110] Number of Smooth Descent Periods of a Stock
 */

// @lc code=start
class Solution
{
public:
    long long getDescentPeriods(vector<int> &prices)
    {
        long long cnt = 0;
        int n = prices.size();
        int r;
        for (int l = 0; l < n; l++)
        {
            r = l;
            while (r + 1 < n && prices[r] - prices[r + 1] == 1)
                r++;
            cnt += (long long)(r - l + 1) * (r - l + 2) / 2;
            l = r;
        }
        return cnt;
    }
};
// @lc code=end

// Note: math + DP