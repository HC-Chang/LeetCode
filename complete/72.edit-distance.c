/*
 * @lc app=leetcode id=72 lang=c
 *
 * [72] Edit Distance
 */

// @lc code=start
int min(int a, int b) { return a < b ? a : b; }
int minDistance(char *word1, char *word2)
{
    int len_1 = strlen(word1);
    int len_2 = strlen(word2);
    int *dp = calloc(len_2 + 1, sizeof(int));

    for (int j = 1; j <= len_2; ++j)
        dp[j] = j;

    int topleft;
    int top;
    for (int i = 1; i <= len_1; i++)
    {
        topleft = dp[0];
        dp[0] = i;

        for (int j = 1; j <= len_2; j++)
        {
            top = dp[j];

            if (word1[i - 1] == word2[j - 1])
                dp[j] = topleft;
            else
                dp[j] = min(min(dp[j - 1], top), topleft) + 1;

            topleft = top;
        }
    }
    int r = dp[len_2];
    free(dp);

    return r;
}
// @lc code=end
