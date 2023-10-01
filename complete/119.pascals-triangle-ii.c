/*
 * @lc app=leetcode id=119 lang=c
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *getRow(int rowIndex, int *returnSize)
{
    *returnSize = rowIndex + 1;
    int *r = calloc(rowIndex + 1, sizeof(int));
    r[0] = 1;
    for (int i = 1; i <= rowIndex; ++i)
    {
        for (int j = i; j >= 1; --j)
            r[j] += r[j - 1];
    }
    return r;
}
// @lc code=end

// Note: DP