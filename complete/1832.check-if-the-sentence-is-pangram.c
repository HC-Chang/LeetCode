/*
 * @lc app=leetcode id=1832 lang=c
 *
 * [1832] Check if the Sentence Is Pangram
 */

// @lc code=start

bool checkIfPangram(char *sentence)
{
    char *hash = calloc(26, sizeof(char));
    while (*sentence)
    {
        hash[*sentence - 'a']++;
        sentence++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (hash[i] == 0)
        {
            free(hash);
            return false;
        }
    }
    free(hash);
    return true;
}
// @lc code=end
