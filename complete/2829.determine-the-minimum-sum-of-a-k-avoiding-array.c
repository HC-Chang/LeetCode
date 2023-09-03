/*
 * @lc app=leetcode id=2829 lang=c
 *
 * [2829] Determine the Minimum Sum of a k-avoiding Array
 */

// @lc code=start
int minimumSum(int n, int k)
{
    int count = k / 2;
    if (count > n)
        count = n;
    return (1 + count) * count / 2 + (2 * k + n - count - 1) * (n - count) / 2;
}
// @lc code=end

// Note: math . greedy