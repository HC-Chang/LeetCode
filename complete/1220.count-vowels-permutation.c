/*
 * @lc app=leetcode id=1220 lang=c
 *
 * [1220] Count Vowels Permutation
 */

// @lc code=start
int countVowelPermutation(int n)
{
    unsigned int dp[5];
    unsigned int tmp[5];
    int mod = 1e9 + 7;
    for (int i = 0; i < 5; i++)
        dp[i] = 1;

    for (int i = 1; i < n; i++)
    {
        tmp[0] = (dp[1]) % mod;
        tmp[1] = (dp[0] + dp[2]) % mod;
        tmp[2] = (dp[0] + dp[1] + dp[3] + dp[4]) % mod;
        tmp[3] = (dp[2] + dp[4]) % mod;
        tmp[4] = (dp[0]) % mod;
        memcpy(dp, tmp, sizeof(dp));
    }
    for (int i = 1; i < 5; i++)
        dp[0] = (dp[0] + dp[i]) % mod;
    return dp[0];
}
// @lc code=end

// Note: DP