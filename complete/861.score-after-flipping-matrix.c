/*
 * @lc app=leetcode id=861 lang=c
 *
 * [861] Score After Flipping Matrix
 */

// @lc code=start
int matrixScore(int **grid, int gridSize, int *gridColSize)
{
    int m = gridSize;
    int n = gridColSize[0];
    int res = (1 << (n - 1)) * m;
    int cnt;
    for (int j = 1; j < n; ++j)
    {
        cnt = 0;
        for (int i = 0; i < m; ++i)
            cnt += (grid[i][j] == grid[i][0]);
        res += fmax(cnt, m - cnt) * (1 << (n - 1 - j));
    }
    return res;
}
// @lc code=end

// Note: bit manipulation + matrix