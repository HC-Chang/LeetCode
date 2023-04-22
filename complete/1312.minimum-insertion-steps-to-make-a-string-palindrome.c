/*
 * @lc app=leetcode id=1312 lang=c
 *
 * [1312] Minimum Insertion Steps to Make a String Palindrome
 */

// @lc code=start
int min(int a, int b) { return a < b ? a : b; }
int minInsertions(char *s)
{
    int n = strlen(s);
    int **dp = malloc((n + 1) * sizeof(int *));
    for (int i = 0; i < n + 1; i++)
        dp[i] = calloc(n + 1, sizeof(int));

    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = i;
        dp[0][i] = i;
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (s[i - 1] == s[n - j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
        }
    int r = dp[n][n] - n;
    for (int i = 0; i < n + 1; i++)
        free(dp[i]);
    free(dp);
    return r;
}
// @lc code=end

// Note: DP + shortest common supersequence