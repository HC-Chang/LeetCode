/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution
{
public:
    bool helper(vector<vector<char>> &board, int m, int n, int i, int j, string words,
                int idx)
    {
        int len_words = words.size();
        if (idx >= len_words)
            return true;
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != words[idx])
            return false;
        char c = board[i][j];
        board[i][j] = '.';
        if (helper(board, m, n, i + 1, j, words, idx + 1) ||
            helper(board, m, n, i, j + 1, words, idx + 1) ||
            helper(board, m, n, i - 1, j, words, idx + 1) ||
            helper(board, m, n, i, j - 1, words, idx + 1))
            return true;
        board[i][j] = c;
        return false;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] != word[0])
                    continue;
                if (helper(board, m, n, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }
};
// @lc code=end

// Note: backtracking