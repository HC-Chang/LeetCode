/*
 * @lc app=leetcode id=1329 lang=c
 *
 * [1329] Sort the Matrix Diagonally
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int sort(void *a, void *b) { return *(int *)a - *(int *)b; }

void arr_sort(int i, int j, int **mat, int m, int n)
{
    int nn = fmin(m, n);
    int *arr = malloc(nn * sizeof(int));
    int idx = 0;
    for (int ii = i, jj = j; ii < m && jj < n; ii++, jj++)
        arr[idx++] = mat[ii][jj];
    qsort(arr, idx, sizeof(int), sort);
    idx = 0;
    for (int ii = i, jj = j; ii < m && jj < n; ii++, jj++)
        mat[ii][jj] = arr[idx++];
}

int **diagonalSort(int **mat, int matSize, int *matColSize, int *returnSize, int **returnColumnSizes)
{
    int n = matColSize[0];

    for (int i = 0; i < matSize; i++)
        arr_sort(i, 0, mat, matSize, n);
    for (int i = 1; i < n; i++)
        arr_sort(0, i, mat, matSize, n);

    *returnSize = matSize;
    returnColumnSizes[0] = matColSize;
    return mat;
}
// @lc code=end

// Note: sorting