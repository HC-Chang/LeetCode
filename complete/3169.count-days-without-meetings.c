/*
 * @lc app=leetcode id=3169 lang=c
 *
 * [3169] Count Days Without Meetings
 */

// @lc code=start
int sort(const void *a, const void *b)
{
    return (*(int **)a)[0] - (*(int **)b)[0];
}

int countDays(int days, int **meetings, int meetingsSize,
              int *meetingsColSize)
{
    qsort(meetings, meetingsSize, sizeof(int *), sort);
    int cnt = 0;
    int l = 0;
    int r = 0;
    for (int i = 0; i < meetingsSize; i++)
    {
        if (r >= meetings[i][0])
            l = r;
        else
        {
            if (meetings[i][0] - r > 1)
                cnt += meetings[i][0] - r - 1;
            l = meetings[i][0];
        }
        if (meetings[i][1] > r)
            r = meetings[i][1];
    }

    return cnt += days - r;
}
// @lc code=end

// Note: sorting