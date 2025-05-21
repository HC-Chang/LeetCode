/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        set<int> x_set;
        set<int> y_set;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    x_set.insert(i);
                    y_set.insert(j);
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (x_set.find(i) != x_set.end() || y_set.find(j) != y_set.end())
                    matrix[i][j] = 0;
            }
        }
    }
};
// @lc code=end

// Note: hash table + matrix