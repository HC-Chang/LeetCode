/*
 * @lc app=leetcode id=2486 lang=c
 *
 * [2486] Append Characters to String to Make Subsequence
 */

// @lc code=start
int appendCharacters(char *s, char *t)
{
    int len_t = strlen(t);
    int idx = 0;
    while (*s)
    {
        if (*s++ == t[idx])
            idx++;
    }
    return len_t - idx;
}
// @lc code=end

// Note: two pointers
