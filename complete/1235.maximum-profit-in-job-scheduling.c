/*
 * @lc app=leetcode id=1235 lang=c
 *
 * [1235] Maximum Profit in Job Scheduling
 */

// @lc code=start
typedef struct
{
    int start_time;
    int end_time;
    int profit;
} JOB;

int binary_search(JOB *j, int right, int target)
{
    int left = 0;
    int mid;
    while (left < right)
    {
        mid = left + (right - left) / 2;
        if (j[mid].end_time > target)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

int sort(const void *a, const void *b)
{
    JOB *x = (JOB *)a;
    JOB *y = (JOB *)b;
    return x->end_time - y->end_time;
}

int jobScheduling(int *startTime, int startTimeSize, int *endTime, int endTimeSize, int *profit, int profitSize)
{
    int n = startTimeSize;
    JOB j[n];
    for (int i = 0; i < n; i++)
    {
        j[i].start_time = startTime[i];
        j[i].end_time = endTime[i];
        j[i].profit = profit[i];
    }

    qsort(j, n, sizeof(JOB), sort);

    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    int k;
    for (int i = 1; i <= n; i++)
    {
        k = binary_search(&j, i - 1, j[i - 1].start_time);
        dp[i] = fmax(dp[i - 1], dp[k] + j[i - 1].profit);
    }
    return dp[n];
}
// @lc code=end

// Note: DP + binary search