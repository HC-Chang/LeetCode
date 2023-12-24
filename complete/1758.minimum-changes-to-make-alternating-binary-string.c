/*
 * @lc app=leetcode id=1758 lang=c
 *
 * [1758] Minimum Changes To Make Alternating Binary String
 */

// @lc code=start
int minOperations(char *s)
{
    int alt = 0;
    int n = strlen(s);
    int chk;
    for (int i = 0; i < n; i++)
    {
        chk = i % 2;
        if (s[i] - '0' == chk)
            ++alt;
    }
    return fmin(alt, n - alt);
}
// @lc code=end
