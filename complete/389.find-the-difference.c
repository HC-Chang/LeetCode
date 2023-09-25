/*
 * @lc app=leetcode id=389 lang=c
 *
 * [389] Find the Difference
 */

// @lc code=start
char findTheDifference(char *s, char *t)
{
    int s_len = strlen(s);
    for (int i = 0; i < strlen(s); i++)
        t[0] += t[i + 1] - s[i];
    return t[0];
}
// @lc code=end
