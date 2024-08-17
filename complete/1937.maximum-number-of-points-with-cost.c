/*
 * @lc app=leetcode id=1937 lang=c
 *
 * [1937] Maximum Number of Points with Cost
 */

// @lc code=start
long long maxPoints(int **points, int pointsSize, int *pointsColSize)
{
    int cols = pointsColSize[0];
    long long currentRow[cols];
    long long previousRow[cols];
    memset(currentRow, 0, sizeof(currentRow));
    memset(previousRow, 0, sizeof(previousRow));

    for (int i = 0; i < pointsSize; i++)
    {
        long long runningMax = 0;

        for (int col = 0; col < cols; ++col)
        {
            runningMax = fmax(runningMax - 1, previousRow[col]);
            currentRow[col] = runningMax;
        }

        runningMax = 0;
        for (int col = cols - 1; col >= 0; --col)
        {
            runningMax = fmax(runningMax - 1, previousRow[col]);
            currentRow[col] = fmax(currentRow[col], runningMax) + points[i][col];
        }

        memcpy(previousRow, currentRow, sizeof(previousRow));
    }

    long long maxPoints = 0;
    for (int col = 0; col < cols; ++col)
        maxPoints = fmax(maxPoints, previousRow[col]);

    return maxPoints;
}
// @lc code=end

// Note: DP

// Official Solution