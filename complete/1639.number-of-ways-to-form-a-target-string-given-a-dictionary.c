/*
 * @lc app=leetcode id=1639 lang=c
 *
 * [1639] Number of Ways to Form a Target String Given a Dictionary
 */

// @lc code=start
int numWays(char **words, int wordsSize, char *target)
{
    long mod = 1e9 + 7;
    int M = wordsSize;
    int L = strlen(words[0]);
    int N = strlen(target);
    if (L < N)
        return 0;

    long **count = malloc(L * sizeof(long *));
    for (int i = 0; i < L; i++)
        count[i] = calloc(26, sizeof(long));

    for (int i = 0; i < L; ++i)
    {
        for (int j = 0; j < M; ++j)
            count[i][words[j][i] - 'a']++;
    }

    long *dp = calloc(N + 1, sizeof(long));
    for (int i = 0; i < L; ++i)
    {
        int prev = 1;
        for (int j = 0; j <= i && j < N; ++j)
        {
            int cur = dp[j + 1];
            dp[j + 1] = ((count[i][target[j] - 'a'] * prev) % mod + dp[j + 1]) % mod;
            prev = cur;
        }
    }

    int r = (int)dp[N];
    for (int i = 0; i < L; i++)
        free(count[i]);
    free(count);
    free(dp);
    return r;
}
// @lc code=end

// Note: DP
