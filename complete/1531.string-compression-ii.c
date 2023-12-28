/*
 * @lc app=leetcode id=1531 lang=c
 *
 * [1531] String Compression II
 */

// @lc code=start
int compress_len(int len)
{
    if (len >= 100)
        return 3;
    if (len >= 10)
        return 2;
    if (len > 1)
        return 1;
    return 0;
}

int dfs(char *s, int left, int quota, int n, int dp[101][101])
{
    if (n - left <= quota)
        return 0;
    if (dp[left][quota] != -1)
        return dp[left][quota];
    dp[left][quota] = (quota ? dfs(s, left + 1, quota - 1, n, dp) : 88888);
    int usages = quota, counts = 0;
    for (int i = left; i != n; ++i)
    {
        if (s[left] == s[i])
            ++counts;
        else if ((--usages) < 0)
            break;
        dp[left][quota] = fmin(dp[left][quota], dfs(s, i + 1, usages, n, dp) + compress_len(counts) + 1);
    }
    return dp[left][quota];
}

int getLengthOfOptimalCompression(char *s, int k)
{
    int n = strlen(s);
    int dp[101][101];
    for (int i = 0; i < 101; i++)
        for (int j = 0; j < 101; j++)
            dp[i][j] = -1;

    return dfs(s, 0, k, n, &dp);
}
// @lc code=end

// Note: DP