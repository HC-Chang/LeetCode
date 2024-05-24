/*
 * @lc app=leetcode id=1255 lang=c
 *
 * [1255] Maximum Score Words Formed by Letters
 */

// @lc code=start
int maxScoreWords(char **words, int wordsSize, char *letters, int lettersSize,
                  int *score, int scoreSize)
{
    int counts[14][128];
    int used[128];
    int total[128];
    int max_score = 0;
    int now;
    memset(counts, 0, sizeof(counts));
    memset(total, 0, sizeof(total));
    for (int i = 0; i != wordsSize; ++i)
        for (int j = 0; j < strlen(words[i]); j++)
            ++counts[i][words[i][j]];
    for (int i = 0; i < lettersSize; i++)
        ++total[letters[i]];
    for (int i = 1; i < (1 << wordsSize); ++i)
    {
        memset(used, 0, sizeof(used));
        for (int j = 0; j != wordsSize; ++j)
            if (i & (1 << j))
                for (int k = 'a'; k <= 'z'; ++k)
                    used[k] += counts[j][k];
        now = 0;
        for (int j = 'a'; j <= 'z'; ++j)
        {
            if (used[j] > total[j])
            {
                now = -1;
                break;
            }
            now += score[j - 'a'] * used[j];
        }
        if (now != -1)
            max_score = fmax(max_score, now);
    }
    return max_score;
}
// @lc code=end

// Note: DP + bit manipulation + backtracking