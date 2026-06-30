/*
 * @lc app=leetcode id=1967 lang=c
 *
 * [1967] Number of Strings That Appear as Substrings in Word
 */

// @lc code=start
int numOfStrings(char **patterns, int patternsSize, char *word)
{
    int cnt = 0;
    for (int i = 0; i < patternsSize; i++)
    {
        if (strstr(word, patterns[i]) != NULL)
            cnt++;
    }
    return cnt;
}
// @lc code=end
