/*
 * @lc app=leetcode id=2579 lang=c
 *
 * [2579] Count Total Number of Colored Cells
 */

// @lc code=start
long long coloredCells(int n)
{
    return (long long)2 * n * n - 2 * n + 1;
}
// @lc code=end

// Note: math
