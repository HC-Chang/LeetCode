/*
 * @lc app=leetcode id=62 lang=c
 *
 * [62] Unique Paths
 */

// @lc code=start
int uniquePaths(int m, int n)
{
    long ans = 1;
    for (int i = 1; i <= n - 1; ++i)
        ans = ans * (m - 1 + i) / i;
    return ans;
}
// @lc code=end
