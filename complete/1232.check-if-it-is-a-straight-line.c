/*
 * @lc app=leetcode id=1232 lang=c
 *
 * [1232] Check If It Is a Straight Line
 */

// @lc code=start
bool checkStraightLine(int **coordinates, int coordinatesSize, int *coordinatesColSize)
{
    if (coordinatesSize == 2)
        return true;
    int dx = coordinates[1][0] - coordinates[0][0];
    int dy = coordinates[1][1] - coordinates[0][1];
    int tmp_dx, tmp_dy;
    for (int i = 2; i < coordinatesSize; i++)
    {
        tmp_dx = coordinates[i][0] - coordinates[0][0];
        tmp_dy = coordinates[i][1] - coordinates[0][1];
        if (dx * tmp_dy != dy * tmp_dx)
            return false;
    }
    return true;
}
// @lc code=end
