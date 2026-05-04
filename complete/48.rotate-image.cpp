/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        vector<int> v;
        int n = matrix.size();
        for (int j = 0; j < n; j++)
        {
            for (int i = n - 1; i >= 0; i--)
                v.push_back(matrix[i][j]);
        }

        int idx = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = v[idx++];
            }
        }
    }
};
// @lc code=end

// Note: math + matrix