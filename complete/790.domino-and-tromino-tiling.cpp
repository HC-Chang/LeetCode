/*
 * @lc app=leetcode id=790 lang=cpp
 *
 * [790] Domino and Tromino Tiling
 */

// @lc code=start
class Solution
{
public:
    int numTilings(int n)
    {
        if (n < 2)
            return 1;
        int k_mod = 1000000007;
        long dp[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; ++i)
            dp[i] = (dp[i - 3] + dp[i - 1] * 2) % k_mod;

        return dp[n];
    }
};
// @lc code=end

// Note: DP

// 509.Fibonacci-Number
// dp[i] = dp[i-1] + dp[i-2]