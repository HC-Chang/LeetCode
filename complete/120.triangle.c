/*
 * @lc app=leetcode id=120 lang=c
 *
 * [120] Triangle
 */

// @lc code=start
int minimumTotal(int **triangle, int triangleSize, int *triangleColSize)
{
    for (int i = triangleSize - 2; i >= 0; i--)
    {
        for (int j = 0; j < triangleColSize[i]; j++)
            triangle[i][j] += fmin(triangle[i + 1][j], triangle[i + 1][j + 1]);
    }
    return triangle[0][0];
}
// @lc code=end

// Note: DP