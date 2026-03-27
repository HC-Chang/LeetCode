/*
 * @lc app=leetcode id=2946 lang=cpp
 *
 * [2946] Matrix Similarity After Cyclic Shifts
 */

// @lc code=start
class Solution
{
public:
    bool areSimilar(vector<vector<int>> &mat, int k)
    {
        int m = mat.size();
        int n = mat[0].size();
        int flag = -1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                flag *= -1;
                if (mat[i][(j + flag * k % n + n) % n] != mat[i][j])
                    return false;
            }
        }

        return true;
    }
};
// @lc code=end
