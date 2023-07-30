/*
 * @lc app=leetcode id=664 lang=c
 *
 * [664] Strange Printer
 */

// @lc code=start
int strangePrinter(char *s)
{
    int s_len = strlen(s);
    int **dp = malloc(s_len * sizeof(int *));
    for (int i = 0; i < s_len; i++)
        dp[i] = malloc(s_len * sizeof(int));
    for (int i = s_len - 1; i >= 0; i--)
    {
        dp[i][i] = 1;
        for (int j = i + 1; j < s_len; j++)
        {
            if (s[i] == s[j])
                dp[i][j] = dp[i + 1][j];
            else
            {
                dp[i][j] = INT_MAX;
                for (int k = i; k < j; k++)
                    dp[i][j] = fmin(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
        }
    }
    int r = dp[0][s_len - 1];
    for (int i = 0; i < s_len; i++)
        free(dp[i]);
    free(dp);
    return r;
}
// @lc code=end

// Note: DP