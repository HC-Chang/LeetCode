/*
 * @lc app=leetcode id=516 lang=c
 *
 * [516] Longest Palindromic Subsequence
 */

// @lc code=start
int longestPalindromeSubseq(char *s)
{
    int s_len = strlen(s);
    if (s_len == 0)
        return 0;

    int **dp = malloc(sizeof(int *) * s_len);
    dp[0] = calloc(s_len, sizeof(int));
    dp[0][0] = 1;
    for (int i = 1; i < s_len; i++)
    {
        dp[i] = calloc(s_len, sizeof(int));
        dp[i][i] = 1;
        dp[i - 1][i] = (s[i - 1] == s[i] ? 2 : 1);
    }

    int head, tail;
    int l_ret, r_ret;
    for (int j = 2; j < s_len; j++)
    {
        for (int i = 0; i + j < s_len; i++)
        {
            head = i;
            tail = i + j;
            if (s[head] == s[tail])
                dp[head][tail] = dp[head + 1][tail - 1] + 2;
            else
            {
                l_ret = dp[head + 1][tail];
                r_ret = dp[head][tail - 1];
                dp[head][tail] = l_ret > r_ret ? l_ret : r_ret;
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
