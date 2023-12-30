/*
 * @lc app=leetcode id=1897 lang=c
 *
 * [1897] Redistribute Characters to Make All Strings Equal
 */

// @lc code=start
bool makeEqual(char **words, int wordsSize)
{
    int hash[26] = {0};
    int len;
    for (int i = 0; i < wordsSize; i++)
    {
        len = strlen(words[i]);
        for (int j = 0; j < len; j++)
            ++hash[words[i][j] - 'a'];
    }

    for (int i = 0; i < 26; i++)
    {
        if (hash[i] % wordsSize != 0)
            return false;
    }
    return true;
}
// @lc code=end

// Note: hash table