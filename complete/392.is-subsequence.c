/*
 * @lc app=leetcode id=392 lang=c
 *
 * [392] Is Subsequence
 */

// @lc code=start
bool isSubsequence(char *s, char *t)
{
    if (!*s)
        return true;
    int s_index = 0;
    int t_len = strlen(t);
    for (int t_index = 0; t_index < t_len; ++t_index)
    {
        if (s[s_index] == t[t_index])
            ++s_index;

        if (s_index == strlen(s))
            return true;
    }

    return false;
}
// @lc code=end
