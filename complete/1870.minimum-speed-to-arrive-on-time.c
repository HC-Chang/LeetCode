/*
 * @lc app=leetcode id=1870 lang=c
 *
 * [1870] Minimum Speed to Arrive on Time
 */

// @lc code=start
bool check(int speed, int *dist, int distSize, double hour)
{
    double res = 0;
    double cost;
    for (int i = 0; i < distSize; ++i)
    {
        cost = dist[i] * 1.0 / speed;
        res += (i == distSize - 1 ? cost : ceil(cost));
    }
    return res <= hour;
}

int minSpeedOnTime(int *dist, int distSize, double hour)
{
    int left = 1;
    int right = 10000000;
    int mid;
    while (left < right)
    {
        mid = (left + right) >> 1;
        if (check(mid, dist, distSize, hour))
            right = mid;
        else
            left = mid + 1;
    }
    return check(left, dist, distSize, hour) ? left : -1;
}
// @lc code=end

// Note: binary search