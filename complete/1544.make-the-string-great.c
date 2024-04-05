/*
 * @lc app=leetcode id=1544 lang=c
 *
 * [1544] Make The String Great
 */

// @lc code=start
char *makeGood(char *s)
{
    int n = strlen(s);
    int idx = 1;
    for (int i = 1; i < n; i++)
    {
        if (idx > 0 && abs(s[i] - s[idx - 1]) == 32)
            idx--;
        else
            s[idx++] = s[i];
    }
    s[idx] = '\0';
    return s;
}
// @lc code=end

// Note: stack