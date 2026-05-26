/*
 * @lc app=leetcode id=3120 lang=c
 *
 * [3120] Count the Number of Special Characters I
 */

// @lc code=start
int numberOfSpecialChars(char *word)
{
    int hash1 = 0, hash2 = 0;
    while (*word)
    {
        if (isupper(*word))
            hash1 |= 1 << (*word - 'A');
        else
            hash2 |= 1 << (*word - 'a');
        word++;
    }
    return __builtin_popcount(hash1 & hash2);
}
// @lc code=end

// Note: hash table