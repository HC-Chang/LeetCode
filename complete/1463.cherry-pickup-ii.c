/*
 * @lc app=leetcode id=1463 lang=c
 *
 * [1463] Cherry Pickup II
 */

// @lc code=start
void swap(int ***f, int ***g)
{
    int **tmp = f[0];
    f[0] = g[0];
    g[0] = tmp;
}

int cherryPickup(int **grid, int gridSize, int *gridColSize)
{
    int m = gridSize;
    int n = gridColSize[0];

    int **f = malloc(n * sizeof(int *));
    int **g = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        f[i] = malloc(n * sizeof(int));
        g[i] = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            f[i][j] = -1;
            g[i][j] = -1;
        }
    }

    f[0][n - 1] = grid[0][0] + grid[0][n - 1];
    for (int i = 1; i < m; ++i)
    {
        for (int j1 = 0; j1 < n; ++j1)
        {
            for (int j2 = 0; j2 < n; ++j2)
            {
                int best = -1;
                for (int dj1 = j1 - 1; dj1 <= j1 + 1; ++dj1)
                {
                    for (int dj2 = j2 - 1; dj2 <= j2 + 1; ++dj2)
                    {
                        if (dj1 >= 0 && dj1 < n && dj2 >= 0 && dj2 < n && f[dj1][dj2] != -1)
                            best = fmax(best, f[dj1][dj2] + (j1 == j2 ? grid[i][j1] : grid[i][j1] + grid[i][j2]));
                    }
                }
                g[j1][j2] = best;
            }
        }
        swap(&f, &g);
    }

    int ans = 0;
    for (int j1 = 0; j1 < n; ++j1)
    {
        for (int j2 = 0; j2 < n; ++j2)
            ans = fmax(ans, f[j1][j2]);
    }
    for (int i = 0; i < n; i++)
    {
        free(f[i]);
        free(g[i]);
    }
    free(f);
    free(g);

    return ans;
}
// @lc code=end

// Note: DP

// Official Solution