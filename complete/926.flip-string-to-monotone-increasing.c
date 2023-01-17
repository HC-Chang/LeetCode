/*
 * @lc app=leetcode id=926 lang=c
 *
 * [926] Flip String to Monotone Increasing
 */

// @lc code=start
#define min(a, b) a < b ? a : b

int minFlipsMonoIncr(char *s)
{
    int ones = 0, ans = 0;
    int len_s = strlen(s);
    for (int i = 0; i < len_s; i++)
    {
        if (s[i] == '1')
            ones++;
        else
            ans = min(ans + 1, ones);
    }
    return ans;
}
// @lc code=end

// DP
