/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int row[9][9] = {}, col[9][9] = {}, box[9][9] = {};
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] == '.')
                    continue;
                int n = board[i][j] - '1';
                if (row[i][n] || col[j][n] || box[i / 3 * 3 + j / 3][n])
                    return false;
                row[i][n] = col[j][n] = box[i / 3 * 3 + j / 3][n] = 1;
            }
        }
        return true;
    }
};
// @lc code=end
