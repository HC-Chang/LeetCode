/*
 * @lc app=leetcode id=1416 lang=c
 *
 * [1416] Restore The Array
 */

// @lc code=start
int numberOfArrays(char *s, int k)
{
    int dp[100001] = {0};
    long long M = 1e9 + 7;
    int n = strlen(s);
    dp[0] = 1;
    long long x;
    for (int i = 1; i <= n; i++)
    {
        x = 0;
        for (int j = 0; j < 10; j++)
        {
            if (i - j <= 0)
                break;
            x = x + pow(10, j) * (s[i - 1 - j] - '0');
            if (x > k)
                break;
            if (x == 0)
                continue;
            if (j > 0 && s[i - 1 - j] == '0')
                continue;
            dp[i] = (dp[i] + dp[i - j - 1]) % M;
        }
    }
    return dp[n];
}
// @lc code=end
