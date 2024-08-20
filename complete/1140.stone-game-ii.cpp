/*
 * @lc app=leetcode id=1140 lang=cpp
 *
 * [1140] Stone Game II
 */

// @lc code=start
class Solution
{
public:
    int helper(vector<int> &sums, int pilesSize, int i, int m,
               vector<vector<int>> &memo)
    {
        if (i + 2 * m >= pilesSize)
            return sums[i];
        if (memo[i][m] > 0)
            return memo[i][m];
        int res = 0;
        for (int x = 1; x <= 2 * m; ++x)
        {
            int cur = sums[i] - sums[i + x];
            res = max(res, cur + sums[i + x] -
                               helper(sums, pilesSize, i + x, max(x, m), memo));
        }
        return memo[i][m] = res;
    }

    int stoneGameII(vector<int> &piles)
    {
        int n = piles.size();
        vector<vector<int>> memo(n, vector<int>(n));
        for (int i = n - 2; i >= 0; --i)
            piles[i] += piles[i + 1];
        int r = helper(piles, n, 0, 1, memo);

        return r;
    }
};
// @lc code=end
