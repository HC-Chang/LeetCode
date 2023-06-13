/*
 * @lc app=leetcode id=2500 lang=c
 *
 * [2500] Delete Greatest Value in Each Row
 */

// Difficulty:Easy

// @lc code=start
int sort(void *a, void *b) { return *(int *)b - *(int *)a; }
int deleteGreatestValue(int **grid, int gridSize, int *gridColSize)
{
    for (int i = 0; i < gridSize; i++)
        qsort(grid[i], gridColSize[i], sizeof(int), sort);
    int sum = 0;
    int tmp;

    for (int i = 0; i < gridColSize[0]; i++)
    {
        tmp = grid[0][i];
        for (int j = 1; j < gridSize; j++)
        {
            if (grid[j][i] > tmp)
                tmp = grid[j][i];
        }
        sum += tmp;
    }
    return sum;
}
// @lc code=end