/*
 * @lc app=leetcode id=934 lang=c
 *
 * [934] Shortest Bridge
 */

// @lc code=start
void dfs(int x, int y, int **grid, int n, int *queue, int *tail)
{
    if (x < 0 || y < 0 || x >= n || y >= n || grid[x][y] != 1)
    {
        return;
    }
    queue[(*tail)++] = x * n + y;
    grid[x][y] = -1;
    dfs(x - 1, y, grid, n, queue, tail);
    dfs(x + 1, y, grid, n, queue, tail);
    dfs(x, y - 1, grid, n, queue, tail);
    dfs(x, y + 1, grid, n, queue, tail);
}

int shortestBridge(int **grid, int gridSize, int *gridColSize)
{
    int n = gridSize;
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                int *queue = (int *)malloc(sizeof(int) * n * n);
                int head = 0, tail = 0;
                dfs(i, j, grid, n, queue, &tail);
                int step = 0;
                while (head != tail)
                {
                    int sz = tail - head;
                    for (int i = 0; i < sz; i++)
                    {
                        int x = queue[head] / n;
                        int y = queue[head] % n;
                        head++;
                        for (int k = 0; k < 4; k++)
                        {
                            int nx = x + dirs[k][0];
                            int ny = y + dirs[k][1];
                            if (nx >= 0 && ny >= 0 && nx < n && ny < n)
                            {
                                if (grid[nx][ny] == 0)
                                {
                                    queue[tail++] = nx * n + ny;
                                    grid[nx][ny] = -1;
                                }
                                else if (grid[nx][ny] == 1)
                                {
                                    free(queue);
                                    return step;
                                }
                            }
                        }
                    }
                    step++;
                }
            }
        }
    }
    return 0;
}
// @lc code=end

// Official Solution