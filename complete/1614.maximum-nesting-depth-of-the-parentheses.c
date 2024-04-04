/*
 * @lc app=leetcode id=1614 lang=c
 *
 * [1614] Maximum Nesting Depth of the Parentheses
 */

// @lc code=start
int maxDepth(char *s)
{
    int max_cnt = 0;
    int cnt = 0;
    int len_s = strlen(s);
    for (int i = 0; i < len_s; i++)
    {
        switch (s[i])
        {
        case '(':
            if (++cnt > max_cnt)
                max_cnt = cnt;
            break;
        case ')':
            cnt--;
            break;
        }
    }
    return max_cnt;
}
// @lc code=end

// Note: stack