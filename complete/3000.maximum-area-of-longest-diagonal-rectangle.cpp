/*
 * @lc app=leetcode id=3000 lang=cpp
 *
 * [3000] Maximum Area of Longest Diagonal Rectangle
 */

// @lc code=start
class Solution
{
public:
    int areaOfMaxDiagonal(vector<vector<int>> &dimensions)
    {
        int max_area = 0;
        int max_diagonal = 0;
        for (auto d : dimensions)
        {
            int diagonal = d[0] * d[0] + d[1] * d[1];
            int area = d[0] * d[1];
            if (diagonal > max_diagonal)
            {
                max_diagonal = diagonal;
                max_area = area;
            }
            else if (diagonal == max_diagonal && area > max_area)
                max_area = area;
        }
        return max_area;
    }
};
// @lc code=end

// Note: array