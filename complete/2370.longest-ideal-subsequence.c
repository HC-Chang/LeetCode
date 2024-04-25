/*
 * @lc app=leetcode id=2370 lang=c
 *
 * [2370] Longest Ideal Subsequence
 */

// @lc code=start
int longestIdealString(char *s, int k)
{
    int n = strlen(s);
    int dp[26] = {0};

    int ret = 0;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        tmp = 0;
        for (int ch = fmax(0, s[i] - 'a' - k); ch <= fmin(25, s[i] - 'a' + k); ch++)
            tmp = fmax(tmp, dp[ch] + 1);

        dp[s[i] - 'a'] = tmp;
        ret = fmax(ret, tmp);
    }

    return ret;
}
// @lc code=end

// Note: DP
