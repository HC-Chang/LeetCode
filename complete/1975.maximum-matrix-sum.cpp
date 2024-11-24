/*
 * @lc app=leetcode id=1975 lang=cpp
 *
 * [1975] Maximum Matrix Sum
 */

// @lc code=start
class Solution
{
public:
    long long maxMatrixSum(vector<vector<int>> &matrix)
    {
        long long ans = 0;
        long long n_cnt = 0;
        long long min_val = INT_MAX;
        long long tmp;
        for (auto mm : matrix)
        {
            for (auto mmm : mm)
            {
                if (mmm < 0)
                    n_cnt++;
                tmp = abs(mmm);
                if (tmp < min_val)
                    min_val = tmp;
                ans += tmp;
            }
        }
        if (n_cnt % 2)
            return ans - 2 * min_val;
        return ans;
    }
};
// @lc code=end

// Note: greedy + matrix
