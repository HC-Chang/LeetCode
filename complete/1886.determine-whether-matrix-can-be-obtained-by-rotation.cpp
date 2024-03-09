/*
 * @lc app=leetcode id=1886 lang=cpp
 *
 * [1886] Determine Whether Matrix Can Be Obtained By Rotation
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> tmp;
    void rotate_90(vector<vector<int>> &mat)
    {
        tmp.assign(mat.begin(), mat.end());
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat.size(); j++)
                mat[i][j] = tmp[mat.size() - j - 1][i];
        }
    }
    bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
    {
        if (mat == target)
            return true;
        for (int i = 0; i < 3; i++)
        {
            rotate_90(mat);
            if (mat == target)
                return true;
        }
        return false;
    }
};
// @lc code=end
