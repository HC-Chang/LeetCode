/*
 * @lc app=leetcode id=1706 lang=c
 *
 * [1706] Where Will the Ball Fall
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findBall(int **grid, int gridSize, int *gridColSize, int *returnSize)
{
    *returnSize = gridColSize[0];

    int *arr = malloc(gridColSize[0] * sizeof(int));
    for (int i = 0; i < gridColSize[0]; i++)
        arr[i] = -1;

    for (int j = 0; j < gridColSize[0]; j++)
    {
        int x = 0, y = j;
        while (x < gridSize)
        {
            if (grid[x][y] == 1)
            {
                if (y == gridColSize[0] - 1)
                    break;
                else if (grid[x][y + 1] == -1)
                    break;
                else
                {
                    x++;
                    y++;
                }
            }
            else
            {
                if (y == 0)
                    break;
                else if (grid[x][y - 1] == 1)
                    break;
                else
                {
                    x++;
                    y--;
                }
            }
        }
        if (x == gridSize)
            arr[j] = y;
    }
    return arr;
}
// @lc code=end
