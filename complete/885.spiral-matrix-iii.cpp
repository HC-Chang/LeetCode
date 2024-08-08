/*
 * @lc app=leetcode id=885 lang=cpp
 *
 * [885] Spiral Matrix III
 */

// @lc code=start
class Solution
{
public:
    void push_val(int i, int j, int *matrix_index, int rows, int cols,
                  vector<vector<int>> &matrix)
    {
        if (i < 0 || i >= rows || j < 0 || j >= cols)
            return;
        matrix[*matrix_index][0] = i;
        matrix[*matrix_index][1] = j;
        ++*matrix_index;
    }

    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,
                                        int cStart)
    {
        int n = rows * cols;
        vector<vector<int>> matrix(n, vector<int>(2, 0));
        int matrix_index = 0;
        push_val(rStart, cStart, &matrix_index, rows, cols, matrix);
        int d = 2;
        while (matrix_index < n)
        {
            push_val(rStart, ++cStart, &matrix_index, rows, cols, matrix);
            for (int i = 1; i < d; ++i)
                push_val(++rStart, cStart, &matrix_index, rows, cols, matrix);
            for (int i = 0; i < d; ++i)
                push_val(rStart, --cStart, &matrix_index, rows, cols, matrix);
            for (int i = 0; i < d; ++i)
                push_val(--rStart, cStart, &matrix_index, rows, cols, matrix);
            for (int i = 0; i < d; ++i)
                push_val(rStart, ++cStart, &matrix_index, rows, cols, matrix);
            d += 2;
        }

        return matrix;
    }
};
// @lc code=end
