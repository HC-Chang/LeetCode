/*
 * @lc app=leetcode id=57 lang=c
 *
 * [57] Insert Interval
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int **insert(int **intervals, int intervalsSize, int *intervalsColSize, int *newInterval, int newIntervalSize, int *returnSize, int **returnColumnSizes)
{
    int **r = malloc(sizeof(int *) * (intervalsSize + 1));
    *returnColumnSizes = malloc(sizeof(int) * (intervalsSize + 1));
    *returnSize = 0;
    int src_chk = 0;
    int dst_chk = 0;

    int i;
    while (i < intervalsSize)
    {
        int src = intervals[i][0];
        int dst = intervals[i][1];
        if (newInterval[0] < src)
        {
            r[*returnSize] = malloc(sizeof(int) * 2);
            (*returnColumnSizes)[*returnSize] = 2;
            r[*returnSize][0] = newInterval[0];
            src_chk = 1;
            break;
        }
        else if (newInterval[0] > dst)
        {
            r[*returnSize] = malloc(sizeof(int) * 2);
            r[*returnSize][0] = src;
            r[*returnSize][1] = dst;
            (*returnColumnSizes)[*returnSize] = 2;
            *returnSize += 1;
            i++;
        }
        else /* src <= newInterval[0] <= dst*/
        {
            r[*returnSize] = malloc(sizeof(int) * 2);
            (*returnColumnSizes)[*returnSize] = 2;
            r[*returnSize][0] = src;
            src_chk = 1;
            break;
        }
    }
    while (i < intervalsSize)
    {
        int src = intervals[i][0];
        int dst = intervals[i][1];
        if (newInterval[1] < src)
        {
            r[*returnSize][1] = newInterval[1];
            *returnSize += 1;
            dst_chk = 1;
            break;
        }
        else if (newInterval[1] > dst)
        {
            i++;
        }
        else /* src <= newInterval[1] <= dst*/
        {
            r[*returnSize][1] = dst;
            *returnSize += 1;
            dst_chk = 1;
            i++;
            break;
        }
    }

    while (i < intervalsSize)
    {
        r[*returnSize] = malloc(sizeof(int) * 2);
        r[*returnSize][0] = intervals[i][0];
        r[*returnSize][1] = intervals[i][1];
        (*returnColumnSizes)[*returnSize] = 2;
        *returnSize += 1;
        i++;
    }

    // Tail edge Case
    if (!dst_chk)
    {
        if (!src_chk)
        {
            r[*returnSize] = malloc(sizeof(int) * 2);
            r[*returnSize][0] = newInterval[0];
            r[*returnSize][1] = newInterval[1];
            (*returnColumnSizes)[*returnSize] = 2;
            *returnSize += 1;
        }
        else
        {
            r[*returnSize][1] = newInterval[1];
            *returnSize += 1;
        }
    }

    return r;
}
// @lc code=end
