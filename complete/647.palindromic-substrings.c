/*
 * @lc app=leetcode id=647 lang=c
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
int countSubstrings(char *s)
{
    int n = strlen(s);
    int r = 0;
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = i; j < n; ++j)
        {
            dp[i][j] = (s[i] == s[j]) && (j - i <= 2 || dp[i + 1][j - 1]);
            if (dp[i][j])
                ++r;
        }
    }
    return r;
}
// @lc code=end

// Note: DP