/*
 * @lc app=leetcode id=2141 lang=c
 *
 * [2141] Maximum Running Time of N Computers
 */

// @lc code=start
int sort(const void *a, const void *b) { return *(int *)b - *(int *)a; }
long long maxRunTime(int n, int *batteries, int batteriesSize)
{
    if (batteriesSize < n)
        return 0;
    qsort(batteries, batteriesSize, sizeof(int), sort);
    long long sum = 0;
    for (int i = 0; i < batteriesSize; i++)
        sum += batteries[i];
    for (int i = 0; i < batteriesSize; i++)
    {
        if (batteries[i] <= sum / n)
            break;
        sum -= batteries[i];
        --n;
    }
    return sum / n;
}
// @lc code=end
