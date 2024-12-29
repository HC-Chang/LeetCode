/*
 * @lc app=leetcode id=1639 lang=cpp
 *
 * [1639] Number of Ways to Form a Target String Given a Dictionary
 */

// @lc code=start
class Solution
{
public:
    int numWays(vector<string> &words, string target)
    {
        long mod = 1e9 + 7;
        int M = words.size();
        int L = words[0].size();
        int N = target.size();
        if (L < N)
            return 0;

        vector<vector<long>> count(L, vector<long>(26));

        for (int i = 0; i < L; ++i)
        {
            for (int j = 0; j < M; ++j)
                count[i][words[j][i] - 'a']++;
        }

        vector<long> dp(N + 1);
        int prev, cur;
        for (int i = 0; i < L; ++i)
        {
            prev = 1;
            for (int j = 0; j <= i && j < N; ++j)
            {
                cur = dp[j + 1];
                dp[j + 1] = ((count[i][target[j] - 'a'] * prev) % mod + dp[j + 1]) % mod;
                prev = cur;
            }
        }

        int r = (int)dp[N];

        return r;
    }
};
// @lc code=end

// Note: DP
