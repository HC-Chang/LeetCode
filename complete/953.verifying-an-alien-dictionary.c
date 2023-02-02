/*
 * @lc app=leetcode id=953 lang=c
 *
 * [953] Verifying an Alien Dictionary
 */

// @lc code=start
#define min(a, b) a < b ? a : b

bool isAlienSorted(char **words, int wordsSize, char *order)
{
    int priority[26] = {};
    for (int i = 0; i < 26; ++i)
        priority[order[i] - 'a'] = i;
    int n = wordsSize;
    for (int i = 1; i < n; ++i)
    {
        int j = 0;
        int m = min(strlen(words[i - 1]), strlen(words[i]));
        for (; j < m && words[i - 1][j] == words[i][j]; ++j)
            ;
        if ((j == m && strlen(words[i - 1]) > strlen(words[i])) || (j < m && priority[words[i - 1][j] - 'a'] > priority[words[i][j] - 'a']))
            return false;
    }
    return true;
}
// @lc code=end
