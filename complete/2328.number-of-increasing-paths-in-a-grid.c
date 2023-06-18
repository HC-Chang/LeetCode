/*
 * @lc app=leetcode id=2328 lang=c
 *
 * [2328] Number of Increasing Paths in a Grid
 */

// @lc code=start
long long dfs(int **grid, int size, int *colsize, int x, int y, int fa, long long dp[][1001])
{
    if (x < 0 || x >= size || y < 0 || y >= colsize[0] || grid[x][y] <= fa)
        return 0;

    if (dp[x][y] != 0)
        return dp[x][y];

    int dx[] = {0, -1, 0, 1};
    int dy[] = {-1, 0, 1, 0};
    long long count = 1;
    for (int i = 0; i < 4; i++)
        count = (count + dfs(grid, size, colsize, x + dx[i], y + dy[i], grid[x][y], dp)) % (1000000007);

    dp[x][y] = count;
    return count;
}

int countPaths(int **grid, int size, int *colsize)
{
    long long dp[1001][1001] = {0};
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < colsize[0]; j++)
        {
            if (dp[i][j] != 0)
                continue;
            dfs(grid, size, colsize, i, j, -1, dp);
        }
    }
    long long int r = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < colsize[0]; j++)
            r = (r + dp[i][j]) % (1000000007);
    }
    return (int)r;
}
// @lc code=end
