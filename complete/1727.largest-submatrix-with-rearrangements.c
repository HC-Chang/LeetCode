/*
 * @lc app=leetcode id=1727 lang=c
 *
 * [1727] Largest Submatrix With Rearrangements
 */

// @lc code=start
int sort(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int largestSubmatrix(int **matrix, int matrixSize, int *matrixColSize)
{
    int m = matrixSize;
    int n = matrixColSize[0];
    int consecutive[m][n];
    memset(consecutive, 0, sizeof(consecutive));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > 0 && matrix[i][j] == 1)
                matrix[i][j] = matrix[i - 1][j] + 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        qsort(matrix[i], n, sizeof(int), sort);
        for (int j = 0; j < n; j++)
            ans = fmax(ans, (n - j) * matrix[i][j]);
    }

    return ans;
}
// @lc code=end
