/*
 * @lc app=leetcode id=931 lang=c
 *
 * [931] Minimum Falling Path Sum
 */

// @lc code=start
int last_min(int i, int j, int** matrix, int matrixSize, int* matrixColSize)
{
    int min = matrix[i-1][j];
    if(j>=1)
        min = fmin(min, matrix[i-1][j-1]);
    if(j<matrixColSize[i]-1)
        min = fmin(min, matrix[i-1][j+1]);
    return min;
}

int sort(void *a, void *b)
{
    return *(int*)a - *(int*)b;
}

int minFallingPathSum(int** matrix, int matrixSize, int* matrixColSize){
    for(int i = 1; i<matrixSize; i++)
    {
        for(int j=0; j<matrixColSize[i]; j++)
            matrix[i][j] += last_min(i,j, matrix, matrixSize, matrixColSize);
    }
    qsort(matrix[matrixSize-1], matrixColSize[matrixSize-1], sizeof(int), sort);
    return matrix[matrixSize-1][0];
}
// @lc code=end
