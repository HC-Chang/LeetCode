/*
 * @lc app=leetcode id=3355 lang=c
 *
 * [3355] Zero Array Transformation I
 */

// @lc code=start
bool isZeroArray(int *nums, int numsSize, int **queries, int queriesSize, int *queriesColSize)
{
    int n = numsSize;
    int d[n + 1];
    memset(d, 0, sizeof(d));
    for (int i = 0; i < queriesSize; i++)
    {
        ++d[queries[i][0]];
        --d[queries[i][1] + 1];
    }
    for (int i = 0, s = 0; i < n; ++i)
    {
        s += d[i];
        if (nums[i] > s)
            return false;
    }
    return true;
}
// @lc code=end

// Note: prefix sum