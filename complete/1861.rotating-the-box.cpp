/*
 * @lc app=leetcode id=1861 lang=cpp
 *
 * [1861] Rotating the Box
 */

// @lc code=start
class Solution
{
public:
    vector<vector<char>> rotate_matrix(vector<vector<char>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<char>> r_mat(n, vector<char>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                r_mat[i][j] = mat[m - 1 - j][i];
        }
        return r_mat;
    }

    void fix_gravity(vector<vector<char>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        int bottom;

        for (int i = 0; i < n; i++)
        {
            bottom = m - 1;
            while (bottom >= 0 && mat[bottom][i] != '.')
                bottom--;

            for (int j = bottom - 1; j >= 0; j--)
            {
                if (mat[j][i] == '#')
                {
                    mat[j][i] = '.';
                    mat[bottom--][i] = '#';
                    while (bottom >= 0 && mat[bottom][i] != '.')
                        bottom--;
                }
                else if (mat[j][i] == '*')
                {
                    bottom = j - 1;
                    while (bottom >= 0 && mat[bottom][i] != '.')
                        bottom--;
                    j = bottom;
                }
            }
        }
    }

    vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
    {
        vector<vector<char>> mat = rotate_matrix(box);
        fix_gravity(mat);

        return mat;
    }
};
// @lc code=end

// Note: two pointers + matrix