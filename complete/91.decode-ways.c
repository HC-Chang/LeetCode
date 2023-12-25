/*
 * @lc app=leetcode id=91 lang=c
 *
 * [91] Decode Ways
 */

// @lc code=start
int numDecodings(char *s)
{
    if (s[0] == '0')
        return 0;
    int n = strlen(s);

    int dp[n + 1];
    memset(dp, 0, sizeof(dp));

    dp[0] = 1;
    dp[1] = (s[0] == '0') ? 0 : dp[0];
    for (int i = 2; i < n + 1; ++i)
    {
        dp[i] = (s[i - 1] == '0') ? 0 : dp[i - 1];
        if ((s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')))
            dp[i] += dp[i - 2];
    }
    return dp[n];
}
// @lc code=end

// Note: DP