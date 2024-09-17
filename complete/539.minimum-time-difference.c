/*
 * @lc app=leetcode id=539 lang=c
 *
 * [539] Minimum Time Difference
 */

// @lc code=start
int sort(void *a, void *b) { return *(int *)a - *(int *)b; }
int findMinDifference(char **timePoints, int timePointsSize)
{
    int t[timePointsSize];
    char tmp[3];
    tmp[2] = 0;
    for (int i = 0; i < timePointsSize; i++)
    {
        memcpy(&tmp, &timePoints[i][0], 2 * sizeof(char));
        t[i] = atoi(&tmp) * 60;
        memcpy(&tmp, &timePoints[i][3], 2 * sizeof(char));
        t[i] += atoi(&tmp);
    }

    qsort(&t, timePointsSize, sizeof(int), sort);
    int tt = t[0];
    for (int i = 0; i < timePointsSize - 1; i++)
        t[i] = t[i + 1] - t[i];
    t[timePointsSize - 1] = 1440 + tt - t[timePointsSize - 1];
    qsort(&t, timePointsSize, sizeof(int), sort);
    return t[0];
}
// @lc code=end

// Note: math + sorting