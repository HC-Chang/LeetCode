/*
 * @lc app=leetcode id=3000 lang=c
 *
 * [3000] Maximum Area of Longest Diagonal Rectangle
 */

// @lc code=start
int areaOfMaxDiagonal(int **dimensions, int dimensionsSize, int *dimensionsColSize)
{
    int max_area = 0;
    int max_diagonal = 0;
    for (int i = 0; i < dimensionsSize; i++)
    {
        int diagonal = dimensions[i][0] * dimensions[i][0] + dimensions[i][1] * dimensions[i][1];
        int area = dimensions[i][0] * dimensions[i][1];
        if (diagonal > max_diagonal)
        {
            max_diagonal = diagonal;
            max_area = area;
        }
        else if (diagonal == max_diagonal && area > max_area)
            max_area = area;
    }
    return max_area;
}
// @lc code=end

// Note: array