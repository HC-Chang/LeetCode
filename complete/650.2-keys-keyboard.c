/*
 * @lc app=leetcode id=650 lang=c
 *
 * [650] 2 Keys Keyboard
 */

// @lc code=start
int minSteps(int n)
{
    int ans = 0;
    int d = 2;
    while (n > 1)
    {
        while (n % d == 0)
        {
            ans += d;
            n /= d;
        }
        d++;
    }
    return ans;
}
// @lc code=end

// Note: math / DP

// Official Solution