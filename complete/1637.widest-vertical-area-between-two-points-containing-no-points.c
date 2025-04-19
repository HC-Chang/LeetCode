/*
 * @lc app=leetcode id=1637 lang=c
 *
 * [1637] Widest Vertical Area Between Two Points Containing No Points
 */

// @lc code=start
int sort(const void *a, const void *b)
{
    int **x = (int **)a;
    int **y = (int **)b;
    if (x[0][0] != y[0][0])
        return x[0][0] - y[0][0];
    return x[0][1] - y[0][1];
}

int maxWidthOfVerticalArea(int **points, int pointsSize, int *pointsColSize)
{
    qsort(points, pointsSize, sizeof(int **), sort);
    int max = INT_MIN;
    for (int i = 1; i < pointsSize; i++)
    {
        if (points[i][0] - points[i - 1][0] > max)
            max = points[i][0] - points[i - 1][0];
    }
    return max;
}

// @lc code=end

// Note: sorting