/*
 * @lc app=leetcode id=2485 lang=c
 *
 * [2485] Find the Pivot Integer
 */

// @lc code=start
int pivotInteger(int n)
{
    int y = n * (n + 1) / 2;
    int x = sqrt(y);
    return x * x == y ? x : -1;
}
// @lc code=end

// Note: prefix sum
