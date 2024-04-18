/*
 * @lc app=leetcode id=463 lang=c
 *
 * [463] Island Perimeter
 */

// @lc code=start
// Solution 2: DFS
int dfs(int i, int j, int **grid, int gridSize, int *gridColSize)
{
    if (i < 0 || i >= gridSize || j < 0 || j >= gridColSize[i])
        return 1;
    if (grid[i][j] == 0)
        return 1;
    if (grid[i][j] == -1)
        return 0;

    grid[i][j] = -1;
    int count = dfs(i + 1, j, grid, gridSize, gridColSize);
    count += dfs(i - 1, j, grid, gridSize, gridColSize);
    count += dfs(i, j + 1, grid, gridSize, gridColSize);
    count += dfs(i, j - 1, grid, gridSize, gridColSize);
    return count;
}
int islandPerimeter(int **grid, int gridSize, int *gridColSize)
{
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridColSize[i]; j++)
        {
            if (grid[i][j] == 1)
                return dfs(i, j, grid, gridSize, gridColSize);
        }
    }
    return 0;
}
// @lc code=end

// Note: DFS

// Solution 1:
// int pass_boundary(int i, int j,int **grid, int gridSize, int *gridColSize)
// {
//     if(i<0 || i >= gridSize || j<0 || j >= gridColSize[i])
//         return 0;
//     return 1;
// }
// int bfs(int i, int j, int **grid, int gridSize, int *gridColSize)
// {
//     if(!pass_boundary(i, j, grid, gridSize, gridColSize))
//         return 0;
//     int count = 4;
//     if(pass_boundary(i+1, j, grid, gridSize, gridColSize))
//     {
//         if(grid[i+1][j])
//             count--;
//     }
//     if(pass_boundary(i-1, j, grid, gridSize, gridColSize))
//     {
//         if(grid[i-1][j])
//             count--;
//     }
//     if(pass_boundary(i, j+1, grid, gridSize, gridColSize))
//     {
//         if(grid[i][j+1])
//             count--;
//     }
//     if(pass_boundary(i, j-1, grid, gridSize, gridColSize))
//     {
//         if(grid[i][j-1])
//             count--;
//     }
//     return count;
// }
// int islandPerimeter(int** grid, int gridSize, int* gridColSize){
//     int len = 0;
//     for(int i =0; i<gridSize; i++)
//     {
//         for(int j=0; j<gridColSize[i]; j++)
//         {
//             if(grid[i][j] == 1)
//                 len += bfs(i, j, grid, gridSize, gridColSize);
//         }
//     }
//     return len;
// }