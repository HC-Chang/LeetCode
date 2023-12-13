/*
 * @lc app=leetcode id=1582 lang=cpp
 *
 * [1582] Special Positions in a Binary Matrix
 */

// @lc code=start
class Solution
{
public:
    int numSpecial(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> mm(mat.size());
        vector<int> nn(mat[0].size());
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 1)
                {
                    ++mm[i];
                    ++nn[j];
                }
            }
        }
        int count = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 1 && mm[i] == 1 && nn[j] == 1)
                    count++;
            }
        }

        return count;
    }
};
// @lc code=end
