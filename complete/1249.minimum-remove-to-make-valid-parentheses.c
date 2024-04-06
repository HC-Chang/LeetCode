/*
 * @lc app=leetcode id=1249 lang=c
 *
 * [1249] Minimum Remove to Make Valid Parentheses
 */

// @lc code=start
char *minRemoveToMakeValid(char *s)
{
    int n = strlen(s);
    int l = 0;
    int r = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ')')
            ++r;
    }

    char *ans = malloc((n + 1) * sizeof(char));
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            if (l == r)
                continue;
            ++l;
        }
        else if (s[i] == ')')
        {
            --r;
            if (l == 0)
                continue;
            --l;
        }
        ans[idx++] = s[i];
    }
    ans[idx] = '\0';
    return ans;
}
// @lc code=end

// Note: stack