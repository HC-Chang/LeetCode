/*
 * @lc app=leetcode id=1380 lang=c
 *
 * [1380] Lucky Numbers in a Matrix
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *luckyNumbers(int **matrix, int matrixSize, int *matrixColSize, int *returnSize)
{
    int m = matrixSize;
    int n = matrixColSize[0];
    int hash[100001] = {0};

    int tmp;
    for (int i = 0; i < m; i++)
    {
        tmp = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] < tmp)
                tmp = matrix[i][j];
        }
        hash[tmp] = 1;
    }

    int *ans = malloc(fmax(m, n) * sizeof(int));
    *returnSize = 0;
    for (int i = 0; i < n; i++)
    {
        tmp = INT_MIN;
        for (int j = 0; j < m; j++)
        {
            if (matrix[j][i] > tmp)
                tmp = matrix[j][i];
        }
        if (hash[tmp])
            ans[(*returnSize)++] = tmp;
    }
    return ans;
}

// @lc code=end

// Note: matrix