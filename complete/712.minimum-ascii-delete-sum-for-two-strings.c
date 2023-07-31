/*
 * @lc app=leetcode id=712 lang=c
 *
 * [712] Minimum ASCII Delete Sum for Two Strings
 */

// @lc code=start
int minimumDeleteSum(char *s1, char *s2)
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int **dp = malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i < len1 + 1; i++)
        dp[i] = calloc((len2 + 1), sizeof(int));

    for (int j = 1; j <= len2; ++j)
        dp[0][j] = dp[0][j - 1] + s2[j - 1];
    for (int i = 1; i <= len1; ++i)
    {
        dp[i][0] = dp[i - 1][0] + s1[i - 1];
        for (int j = 1; j <= len2; ++j)
            dp[i][j] = (s1[i - 1] == s2[j - 1]) ? dp[i - 1][j - 1] : fmin(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
    }

    int r = dp[len1][len2];
    for (int i = 0; i < len1 + 1; i++)
        free(dp[i]);
    free(dp);
    return r;
}
// @lc code=end

// Note: DP