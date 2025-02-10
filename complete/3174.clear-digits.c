/*
 * @lc app=leetcode id=3174 lang=c
 *
 * [3174] Clear Digits
 */

// @lc code=start
char *clearDigits(char *s)
{
    int idx = 0;
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        if (isdigit(s[i]) && i > 0)
            --idx;
        else
            s[idx++] = s[i];
    }
    s[idx] = '\0';
    return s;
}
// @lc code=end

// Note: stack