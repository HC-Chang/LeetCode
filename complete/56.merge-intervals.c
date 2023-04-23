/*
 * @lc app=leetcode id=56 lang=c
 *
 * [56] Merge Intervals
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int sort(const void *a, const void *b) { return (*(int **)a)[0] - (*(int **)b)[0]; }

int **merge(int **intervals, int intervalsSize, int *intervalsColSize, int *returnSize, int **returnColumnSizes)
{
    int **r = malloc(intervalsSize * sizeof(int *));
    returnColumnSizes[0] = malloc(sizeof(int) * intervalsSize);
    *returnSize = 0;
    if (intervalsSize == 0)
        return r;

    qsort(intervals, intervalsSize, sizeof(int *), sort);

    int *prev = intervals[0];
    for (int index = 1; index < intervalsSize; index++)
    {
        if (prev[1] >= intervals[index][0])
            prev[1] = ((prev[1] <= intervals[index][1]) ? intervals[index][1] : prev[1]);
        else
        {
            r[*returnSize] = malloc(sizeof(int) * 2);
            r[*returnSize][0] = prev[0];
            r[*returnSize][1] = prev[1];
            (*returnColumnSizes)[*returnSize] = 2;
            *returnSize += 1;
            prev = intervals[index];
        }
    }

    r[*returnSize] = malloc(sizeof(int) * 2);
    r[*returnSize][0] = prev[0];
    r[*returnSize][1] = prev[1];
    returnColumnSizes[0][*returnSize] = 2;
    *returnSize += 1;
    r = realloc(r, (*returnSize) * sizeof(int *));

    return r;
}

// @lc code=end

// Note: interval