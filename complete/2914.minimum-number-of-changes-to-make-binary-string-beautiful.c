/*
 * @lc app=leetcode id=2914 lang=c
 *
 * [2914] Minimum Number of Changes to Make Binary String Beautiful
 */

// @lc code=start
int minChanges(char *s)
{
    int cnt = 0;
    int n = strlen(s);
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i * 2] != s[i * 2 + 1])
            cnt++;
    }

    return cnt;
}
// @lc code=end
