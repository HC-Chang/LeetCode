/*
 * @lc app=leetcode id=74 lang=c
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
bool searchMatrix(int **matrix, int matrixSize, int *matrixColSize, int target)
{
    int left = 0;
    int right = matrixSize - 1;
    int middle;
    while (left <= right)
    {
        middle = left + (right - left) / 2;
        if (matrix[middle][0] == target)
            return true;
        else if (matrix[middle][0] > target)
            right = middle - 1;
        else if (matrix[middle][0] < target)
            left = middle + 1;
    }
    int x = left - 1 > 0 ? left - 1 : 0;
    left = 0;
    right = matrixColSize[0] - 1;
    while (left <= right)
    {
        middle = left + (right - left) / 2;
        if (matrix[x][middle] == target)
            return true;
        else if (matrix[x][middle] > target)
            right = middle - 1;
        else if (matrix[x][middle] < target)
            left = middle + 1;
    }
    return false;
}
// @lc code=end
