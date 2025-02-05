/*
 * @lc app=leetcode id=1790 lang=c
 *
 * [1790] Check if One String Swap Can Make Strings Equal
 */

// @lc code=start
bool areAlmostEqual(char *s1, char *s2)
{
    int n1 = strlen(s1);
    int n2 = strlen(s2);
    if (n1 != n2)
        return false;
    int idx = -1;
    int diff_cnt = 0;
    for (int i = 0; i < n1; i++)
    {
        if (s1[i] != s2[i])
        {
            ++diff_cnt;
            if (idx == -1)
                idx = i;
            else if (s1[idx] != s2[i] || s2[idx] != s1[i] || diff_cnt > 2)
                return false;
        }
    }

    return diff_cnt % 2 == 0;
}
// @lc code=end

// Note: hash table + counting