/*
 * @lc app=leetcode id=1684 lang=c
 *
 * [1684] Count the Number of Consistent Strings
 */

// @lc code=start
int countConsistentStrings(char *allowed, char **words, int wordsSize)
{
    int hash = 0;
    int n_allowed = strlen(allowed);
    for (int i = 0; i < n_allowed; i++)
        hash |= 1 << (allowed[i] - 'a');

    int cnt = 0;
    int n;
    int pass = 0;
    for (int i = 0; i < wordsSize; i++)
    {
        n = strlen(words[i]);
        pass = 0;
        for (int j = 0; j < n; j++)
        {
            if (!(hash & 1 << (words[i][j] - 'a')))
            {
                pass = 1;
                break;
            }
        }
        if (!pass)
            cnt++;
    }
    return cnt;
}
// @lc code=end

// Note: hash table + bit manipulation