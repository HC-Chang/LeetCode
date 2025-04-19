/*
 * @lc app=leetcode id=2187 lang=c
 *
 * [2187] Minimum Time to Complete Trips
 */

// @lc code=start
int if_complete(int *time, int timeSize, int totalTrips, long long max_t)
{
    long long count = 0;
    for (int i = 0; i < timeSize; i++)
        count += max_t / time[i];
    return count >= totalTrips;
}

int sort(const void *a, const void *b) { return *(int *)a - *(int *)b; }

long long minimumTime(int *time, int timeSize, int totalTrips)
{
    qsort(time, timeSize, sizeof(int), sort);
    long long h = (long long)time[timeSize - 1] * totalTrips;
    long long l = 1;
    long long mid;
    long long r = INT_MAX;
    while (l <= h)
    {
        mid = l + (h - l) / 2;
        if (if_complete(time, timeSize, totalTrips, mid))
        {
            r = mid;
            h = mid - 1;
        }
        else
            l = mid + 1;
    }
    return r;
}
// @lc code=end

// Note: binary search