/*
 * @lc app=leetcode id=2707 lang=c
 *
 * [2707] Extra Characters in a String
 */

// @lc code=start
unsigned long hash(unsigned char *str, int count)
{
    unsigned long hash = 5381;
    for (int i = 0; i < count; i++)
        hash = ((hash << 5) + hash) + str[i];

    return hash;
}

int minExtraChar(char *s, char **dictionary, int dictionarySize)
{
    unsigned long hashs[dictionarySize];
    for (int i = 0; i < dictionarySize; i++)
        hashs[i] = hash(dictionary[i], strlen(dictionary[i]));

    int n = strlen(s);
    int dp[n + 1];
    dp[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + 1;
        for (int j = 0; j < i; ++j)
        {
            for (int k = 0; k < dictionarySize; k++)
            {
                if (hash(s + j, i - j) == hashs[k])
                    dp[i] = fmin(dp[i], dp[j]);
            }
        }
    }
    return dp[n];
}
// @lc code=end

// Note: hash . DP . Trie