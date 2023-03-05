/*
 * @lc app=leetcode id=139 lang=c
 *
 * [139] Word Break
 */

// @lc code=start
bool wordBreak(char *s, char **wordDict, int wordDictSize)
{
    int s_len = strlen(s);
    int *dp = calloc(s_len + 1, sizeof(int));
    dp[0] = 1;
    int len;
    int index;
    for (int i = 1; i <= s_len; i++)
    {
        for (int j = 0; j < wordDictSize; j++)
        {
            len = strlen(wordDict[j]);
            index = i - len;
            if (index < 0)
                continue;
            dp[i] = (dp[index] && !strncmp(s + index, wordDict[j], len)) || dp[i];
        }
    }

    int r = dp[s_len];
    free(dp);

    return r;
}
// @lc code=end

// Note: DP