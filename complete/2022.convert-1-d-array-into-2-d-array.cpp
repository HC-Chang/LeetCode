/*
 * @lc app=leetcode id=2022 lang=cpp
 *
 * [2022] Convert 1D Array Into 2D Array
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
    {
        if (original.size() != m * n)
            return {};

        vector<vector<int>> arr(m, vector<int>(n));
        int idx = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                arr[i][j] = original[idx++];
        }
        return arr;
    }
};
// @lc code=end

// Note: array . matrix