/*
 * @lc app=leetcode id=920 lang=c
 *
 * [920] Number of Music Playlists
 */

// @lc code=start
int numMusicPlaylists(int n, int goal, int k)
{
    int mod = 1e9 + 7;
    long **dp = malloc((goal + 1) * sizeof(long *));
    for (int i = 0; i <= goal; i++)
        dp[i] = calloc(n + 1, sizeof(long));
    dp[0][0] = 1;
    for (int i = 1; i <= goal; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            dp[i][j] = (dp[i - 1][j - 1] * (n - (j - 1))) % mod;
            if (j > k)
                dp[i][j] = (dp[i][j] + dp[i - 1][j] * (j - k) % mod) % mod;
        }
    }

    int r = dp[goal][n];
    for (int i = 0; i <= goal; i++)
        free(dp[i]);
    free(dp);
    return r;
}
// @lc code=end

// Note: DP
