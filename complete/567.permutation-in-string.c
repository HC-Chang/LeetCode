/*
 * @lc app=leetcode id=567 lang=c
 *
 * [567] Permutation in String
 */

// @lc code=start
bool checkInclusion(char *s1, char *s2)
{
    int s1_len = strlen(s1);
    int s2_len = strlen(s2);
    if (s1_len > s2_len)
        return false;

    int count[26] = {0};
    for (int i = 0; i < s1_len; i++)
        count[s1[i] - 'a']++;
        
    for (int i = 0, j = 0; j < s2_len; ++j)
    {
        if (--count[s2[j] - 'a'] < 0)
        {
            while (s2[i] != s2[j])
                count[s2[i++] - 'a']++;
            count[s2[i++] - 'a']++;
        }
        if (j - i + 1 == s1_len)
            return true;
    }

    return false;
}
// @lc code=end
