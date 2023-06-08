/*
 * @lc app=leetcode id=1351 lang=c
 *
 * [1351] Count Negative Numbers in a Sorted Matrix
 */

// @lc code=start
// Solution 2: Binary Search
int binary_search(int *arr, int arrSize)
{
    int left = 0;
    int right = arrSize - 1;
    int mid;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (arr[mid] < 0)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return arrSize - left;
}
int countNegatives(int **grid, int gridSize, int *gridColSize)
{
    int count = 0;
    for (int i = 0; i < gridSize; i++)
        count += binary_search(grid[i], gridColSize[i]);
    return count;
}
// @lc code=end

// Solution 1:
// int countNegatives(int **grid, int gridSize, int *gridColSize)
// {
//     int count = 0;
//     for (int i = 0; i < gridSize; i++)
//     {
//         for (int j = gridColSize[i] - 1; j >= 0; j--)
//         {
//             if (grid[i][j] < 0)
//                 count++;
//         }
//     }
//     return count;
// }