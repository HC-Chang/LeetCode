/*
 * @lc app=leetcode id=973 lang=c
 *
 * [973] K Closest Points to Origin
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int sort(void *a, void *b)
{
    int dist1 = (*(int **)a)[0] * (*(int **)a)[0] + (*(int **)a)[1] * (*(int **)a)[1];
    int dist2 = (*(int **)b)[0] * (*(int **)b)[0] + (*(int **)b)[1] * (*(int **)b)[1];
    return dist1 - dist2;
}

int **kClosest(int **points, int pointsSize, int *pointsColSize, int k, int *returnSize, int **returnColumnSizes)
{
    *returnSize = k;
    *returnColumnSizes = pointsColSize;
    qsort(points, pointsSize, sizeof(int *), sort);
    return points;
}
// @lc code=end
