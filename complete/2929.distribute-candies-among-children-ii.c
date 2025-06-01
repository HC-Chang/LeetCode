/*
 * @lc app=leetcode id=2929 lang=c
 *
 * [2929] Distribute Candies Among Children II
 */

// @lc code=start
long long distributeCandies(int n, int limit)
{
    int nn = fmin(n, limit);
    long long ans = 0;
    for (int i = 0; i <= nn; i++)
    {
        if (n - i > 2 * limit)
            continue;

        ans += fmin(n - i, limit) - fmax(0, n - i - limit) + 1;
    }
    return ans;
}
// @lc code=end

// Note: math + enumeration