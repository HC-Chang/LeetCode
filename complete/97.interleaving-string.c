/*
 * @lc app=leetcode id=97 lang=c
 *
 * [97] Interleaving String
 */

// @lc code=start
bool isInterleave(char *s1, char *s2, char *s3)
{
    int s1_len = strlen(s1);
    int s2_len = strlen(s2);
    int s3_len = strlen(s3);
    if (s1_len + s2_len != s3_len)
        return false;
    bool dp[2][201] = {0};
    dp[0][0] = true;
    for (int i = 0; i != s2_len; ++i)
        dp[0][i + 1] = (s2[i] == s3[i] && dp[0][i]);
    for (int i = 0; i != s1_len; ++i)
    {
        dp[!(i & 1)][0] = (s1[i] == s3[i] && dp[i & 1][0]);
        for (int j = 0; j != s2_len; ++j)
            dp[!(i & 1)][j + 1] = (s1[i] == s3[i + j + 1] && dp[i & 1][j + 1]) || (s2[j] == s3[i + j + 1] && dp[!(i & 1)][j]);
    }
    return dp[s1_len & 1][s2_len];
}
// @lc code=end

// Note: DP