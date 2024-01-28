/*
 * @lc app=leetcode id=1074 lang=c
 *
 * [1074] Number of Submatrices That Sum to Target
 */

// @lc code=start
int numSubmatrixSumTarget(int **matrix, int matrixSize, int *matrixColSize, int target)
{
    int m = matrixSize;
    int n = matrixColSize[0];
    int res = 0;

    int sums[m];
    int sum;
    for (int l = 0; l < n; ++l)
    {
        memset(sums, 0, sizeof(sums));
        for (int r = l; r < n; ++r)
        {
            for (int i = 0; i < m; ++i)
                sums[i] += matrix[i][r];
            for (int i = 0; i < m; ++i)
            {
                sum = 0;
                for (int j = i; j < m; ++j)
                {
                    sum += sums[j];
                    if (sum == target)
                        ++res;
                }
            }
        }
    }

    return res;
}
// @lc code=end

// Note: prefix sum + sliding window