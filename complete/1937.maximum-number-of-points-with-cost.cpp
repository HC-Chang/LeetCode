/*
 * @lc app=leetcode id=1937 lang=cpp
 *
 * [1937] Maximum Number of Points with Cost
 */

// @lc code=start
class Solution
{
public:
    long long maxPoints(vector<vector<int>> &points)
    {
        int cols = points[0].size();
        vector<long long> currentRow(cols), previousRow(cols);

        for (auto &row : points)
        {
            long long runningMax = 0;

            for (int col = 0; col < cols; ++col)
            {
                runningMax = max(runningMax - 1, previousRow[col]);
                currentRow[col] = runningMax;
            }

            runningMax = 0;
            for (int col = cols - 1; col >= 0; --col)
            {
                runningMax = max(runningMax - 1, previousRow[col]);
                currentRow[col] = max(currentRow[col], runningMax) + row[col];
            }

            previousRow = currentRow;
        }

        long long maxPoints = 0;
        for (int col = 0; col < cols; ++col)
            maxPoints = max(maxPoints, previousRow[col]);

        return maxPoints;
    }
};
// @lc code=end

// Note: DP

// Official Solution