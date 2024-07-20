/*
 * @lc app=leetcode id=1605 lang=cpp
 *
 * [1605] Find Valid Matrix Given Row and Column Sums
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> restoreMatrix(vector<int> &rowSum,
                                      vector<int> &colSum)
    {
        int n = rowSum.size();
        int m = colSum.size();

        vector<vector<int>> origMatrix(n, vector<int>(m, 0));
        int i = 0, j = 0;

        while (i < n && j < m)
        {
            origMatrix[i][j] = min(rowSum[i], colSum[j]);

            rowSum[i] -= origMatrix[i][j];
            colSum[j] -= origMatrix[i][j];

            rowSum[i] == 0 ? i++ : j++;
        }
        return origMatrix;
    }
};
// @lc code=end

// Note: greedy + matrix

// Official Solution