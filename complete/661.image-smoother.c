/*
 * @lc app=leetcode id=661 lang=c
 *
 * [661] Image Smoother
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **imageSmoother(int **img, int imgSize, int *imgColSize, int *returnSize, int **returnColumnSizes)
{
    *returnSize = imgSize;
    returnColumnSizes[0] = imgColSize;

    int **ans = malloc(imgSize * sizeof(int *));
    for (int i = 0; i < imgSize; i++)
        ans[i] = malloc(imgColSize[i] * sizeof(int));

    int cnt;
    int sum;
    int ii;
    int jj;
    for (int i = 0; i < imgSize; i++)
    {
        for (int j = 0; j < imgColSize[i]; j++)
        {
            cnt = 0;
            sum = 0;
            ii = i - 1;
            jj = j - 1;
            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    if (ii + x >= 0 && jj + y >= 0 && ii + x < imgSize && jj + y < imgColSize[i])
                    {
                        sum += img[ii + x][jj + y];
                        cnt++;
                    }
                }
            }
            ans[i][j] = sum / cnt;
        }
    }
    return ans;
}
// @lc code=end
