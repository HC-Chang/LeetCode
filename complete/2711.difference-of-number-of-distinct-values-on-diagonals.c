/*
 * @lc app=leetcode id=2711 lang=c
 *
 * [2711] Difference of Number of Distinct Values on Diagonals
 */

// Difficulty: Medium

// Given a 0-indexed 2D grid of size m x n, you should find the matrix answer of size m x n.

// The value of each cell (r, c) of the matrix answer is calculated in the following way:
// Let topLeft[r][c] be the number of distinct values in the top-left diagonal of the cell (r, c) in the matrix grid.
// Let bottomRight[r][c] be the number of distinct values in the bottom-right diagonal of the cell (r, c) in the matrix grid.
// Then answer[r][c] = |topLeft[r][c] - bottomRight[r][c]|.

// Return the matrix answer.

// A matrix diagonal is a diagonal line of cells starting from some cell in either the topmost row or leftmost column and going in the bottom-right direction until reaching the matrix's end.
// A cell (r1, c1) belongs to the top-left diagonal of the cell (r, c), if both belong to the same diagonal and r1 < r. Similarly is defined bottom-right diagonal.

// Constraints:
// m == grid.length
// n == grid[i].length
// 1 <= m, n, grid[i][j] <= 50

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int lt_dcount(int i, int j, int **grid, int gridSize, int *gridColSize)
{
    int visited[50] = {0};
    int count = 0;
    i--;
    j--;
    while (i >= 0 && j >= 0)
    {
        if (!visited[grid[i][j] - 1])
        {
            count++;
            visited[grid[i][j] - 1] = 1;
        }
        i--;
        j--;
    }
    return count;
}

int rb_dcount(int i, int j, int **grid, int gridSize, int *gridColSize)
{
    int visited[50] = {0};
    int count = 0;
    i++;
    j++;
    while (i < gridSize && j < gridColSize[i])
    {
        if (!visited[grid[i][j] - 1])
        {
            count++;
            visited[grid[i][j] - 1] = 1;
        }
        i++;
        j++;
    }
    return count;
}

int **differenceOfDistinctValues(int **grid, int gridSize, int *gridColSize, int *returnSize, int **returnColumnSizes)
{
    *returnSize = gridSize;
    returnColumnSizes[0] = gridColSize;

    int **r = malloc(*returnSize * sizeof(int *));
    for (int i = 0; i < gridSize; i++)
        r[i] = malloc(gridColSize[i] * sizeof(int));
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridColSize[i]; j++)
            r[i][j] = abs(lt_dcount(i, j, grid, gridSize, gridColSize) - rb_dcount(i, j, grid, gridSize, gridColSize));
    }

    return r;
}
// @lc code=end