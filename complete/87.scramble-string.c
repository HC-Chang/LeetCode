/*
 * @lc app=leetcode id=87 lang=c
 *
 * [87] Scramble String
 */

// @lc code=start
bool isScramble(char *s1, char *s2)
{
    int n = strlen(s1);
    bool dp[n + 1][n][n];
    memset(dp, false, sizeof(dp));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n - i; j++)
        {
            for (int k = 0; k <= n - i; k++)
            {
                if (i == 1)
                    dp[1][j][k] = (s1[j] == s2[k]) ? true : false;
                else
                {
                    for (int p = 1; p < i; p++)
                    {
                        if ((dp[p][j][k] && dp[i - p][j + p][k + p]) ||
                            (dp[p][j + i - p][k] && dp[i - p][j][k + p]))
                        {
                            dp[i][j][k] = true;
                            break;
                        }
                    }
                }
            }
        }
    }

    return dp[n][0][0];
}
// @lc code=end
