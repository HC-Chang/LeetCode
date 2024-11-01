/*
 * @lc app=leetcode id=1957 lang=c
 *
 * [1957] Delete Characters to Make Fancy String
 */

// @lc code=start
char *makeFancyString(char *s)
{
    int n = strlen(s);
    int idx = 0;
    char cc = ' ';
    int cnt = 1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != cc)
        {
            cc = s[i];
            cnt = 1;
        }
        else if (++cnt >= 3)
            continue;
        s[idx++] = s[i];
    }
    s[idx] = '\0';
    return s;
}
// @lc code=end

// Note: string