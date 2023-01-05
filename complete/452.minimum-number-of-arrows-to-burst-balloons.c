/*
 * @lc app=leetcode id=452 lang=c
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

// @lc code=start
int sort(void *a, void *b)
{
    int x = ((int **)a)[0][1];
    int y = ((int **)b)[0][1];
    return x > y ? 1 : 0;
}

int findMinArrowShots(int **points, int pointsSize, int *pointsColSize)
{
    qsort(points, pointsSize, sizeof(int *), sort);
    int count = 1;
    int max_x = points[0][1];
    for (int i = 1; i < pointsSize; i++)
    {
        if (points[i][0] <= max_x)
            continue;
        else
        {
            max_x = points[i][1];
            count++;
        }
    }
    return count;
}
// @lc code=end
