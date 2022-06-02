/*
 * @lc app=leetcode id=200 lang=c
 *
 * [200] Number of Islands
 */

// @lc code=start

void print_map(char **grid, int gridSize, int *gridColSize)
{
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridColSize[i]; j++)
        {
            printf("%c", grid[i][j]);
        }
        printf("\r\n");
    }
    printf("---\r\n");
}

// 0: all zero
// 1: not zero
int is_not_zero(char **grid, int gridSize, int *gridColSize)
{
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridColSize[i]; j++)
        {
            if (grid[i][j] != '0')
            {
                return 1;
            }
        }
    }

    return 0;
}

void find_island(char **grid, int gridSize, int *gridColSize, int x, int y)
{
    if (x > gridSize - 1 || x < 0 || y > gridColSize[x] - 1 || y < 0)
    {
        return;
    }
    if (grid[x][y] == '0')
    {
        return;
    }

    grid[x][y] = '0';
    find_island(grid, gridSize, gridColSize, x, y - 1);
    find_island(grid, gridSize, gridColSize, x, y + 1);
    find_island(grid, gridSize, gridColSize, x - 1, y);
    find_island(grid, gridSize, gridColSize, x + 1, y);
    // print_map(grid, gridSize, gridColSize);
}

int numIslands(char **grid, int gridSize, int *gridColSize)
{
    if (gridSize == 0)
    {
        return 0;
    }

    int island_count = 0;

    do
    {
        for (int i = 0; i < gridSize; i++)
        {
            for (int j = 0; j < gridColSize[i]; j++)
            {
                if (grid[i][j] != '0')
                {
                    find_island(grid, gridSize, gridColSize, i, j);
                    island_count++;
                    break;
                }
            }
        }

        // print_map(grid, gridSize, gridColSize);
    } while (is_not_zero(grid, gridSize, gridColSize));

    return island_count;
}
// @lc code=end
