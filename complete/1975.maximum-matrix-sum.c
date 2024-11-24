/*
 * @lc app=leetcode id=1975 lang=c
 *
 * [1975] Maximum Matrix Sum
 */

// @lc code=start
long long maxMatrixSum(int **matrix, int matrixSize, int *matrixColSize)
{
    long long ans = 0;
    long long n_cnt = 0;
    long long min_val = INT_MAX;
    long long tmp;
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixColSize[i]; j++)
        {
            if (matrix[i][j] < 0)
                n_cnt++;
            tmp = abs(matrix[i][j]);
            if (tmp < min_val)
                min_val = tmp;
            ans += tmp;
        }
    }
    if (n_cnt % 2)
        return ans - 2 * min_val;
    return ans;
}
// @lc code=end

// Note: greedy + matrix
