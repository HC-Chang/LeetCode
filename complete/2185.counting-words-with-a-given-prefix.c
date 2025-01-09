/*
 * @lc app=leetcode id=2185 lang=c
 *
 * [2185] Counting Words With a Given Prefix
 */

// @lc code=start
int prefixCount(char **words, int wordsSize, char *pref)
{
    int cnt = 0;
    int n = strlen(pref);
    for (int i = 0; i < wordsSize; i++)
    {
        if (strlen(words[i]) < n)
            continue;
        words[i][n] = 0;
        if (!strcmp(words[i], pref))
            ++cnt;
    }
    return cnt;
}
// @lc code=end
