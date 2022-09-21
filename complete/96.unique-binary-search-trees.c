/*
 * @lc app=leetcode id=96 lang=c
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start

int numTrees(int n)
{
    long count = 1;
    for (int i = n + 1; i <= 2 * n; i++)
    {
        count = count * i / (i - n);
    }
    return count / (n + 1);
}
// @lc code=end
// 卡塔蘭數: (C 的 2n 取 n) / (n + 1)
