/*
 * @lc app=leetcode id=392 lang=c
 *
 * [392] Is Subsequence
 */

// @lc code=start
// Solution 2: two-pointer
bool isSubsequence(char *s, char *t)
{
    int l1 = strlen(s);
    int l2 = strlen(t);
    if (l1 > l2)
        return false;
    int s_index = 0;
    int t_index = 0;
    while (s_index < l1 && t_index < l2)
    {
        if (s[s_index] == t[t_index])
            s_index++;
        t_index++;
    }
    if (s_index == l1)
        return true;
    return false;
}
// @lc code=end

// Note: two-pointer

// Solution 1:
// bool isSubsequence(char *s, char *t)
// {
//     if (!*s)
//         return true;
//     int s_index = 0;
//     int t_len = strlen(t);
//     for (int t_index = 0; t_index < t_len; ++t_index)
//     {
//         if (s[s_index] == t[t_index])
//             ++s_index;

//         if (s_index == strlen(s))
//             return true;
//     }

//     return false;
// }