/*
 * @lc app=leetcode id=935 lang=c
 *
 * [935] Knight Dialer
 */

// @lc code=start
int knightDialer(int n)
{
    if (n == 1)
        return 10;
    long long dp[10];
    long long last[10];
    int mod = 1e9 + 7;
    for (int i = 0; i < 10; i++)
        dp[i] = 1;
    dp[5] = 0;
    for (int i = 1; i < n; i++)
    {
        memcpy(last, dp, sizeof(dp));
        dp[0] = (last[4] + last[6]) % mod;
        dp[1] = (last[6] + last[8]) % mod;
        dp[2] = (last[7] + last[9]) % mod;
        dp[3] = (last[4] + last[8]) % mod;
        dp[4] = (last[0] + last[3] + last[9]) % mod;
        dp[6] = (last[0] + last[1] + last[7]) % mod;
        dp[7] = (last[2] + last[6]) % mod;
        dp[8] = (last[1] + last[3]) % mod;
        dp[9] = (last[2] + last[4]) % mod;
    }
    for (int i = 1; i < 10; i++)
        dp[0] += dp[i];
    return dp[0] % mod;
}

// @lc code=end

// Note: DP