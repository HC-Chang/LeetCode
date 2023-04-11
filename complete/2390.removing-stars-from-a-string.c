/*
 * @lc app=leetcode id=2390 lang=c
 *
 * [2390] Removing Stars From a String
 */

// @lc code=start
char *removeStars(char *s)
{
    int index = 0;
    int s_len = strlen(s);
    for (int i = 0; i < s_len; i++)
    {
        if (s[i] != '*')
            s[index++] = s[i];
        else
            index--;
    }
    s[index] = '\0';
    return s;
}
// @lc code=end
