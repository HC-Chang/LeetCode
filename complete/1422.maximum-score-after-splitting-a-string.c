/*
 * @lc app=leetcode id=1422 lang=c
 *
 * [1422] Maximum Score After Splitting a String
 */

// @lc code=start
int maxScore(char *s)
{
    int n = strlen(s);
    int cur = s[0] == '0' ? 1 : 0;
    for (int i = 1; i < n; i++)
        cur += s[i] - '0';
    int ans = cur;
    for (int i = 1; i < n - 1; i++)
    {
        cur += s[i] == '0' ? 1 : -1;
        ans = fmax(ans, cur);
    }
    return ans;
}
// @lc code=end
