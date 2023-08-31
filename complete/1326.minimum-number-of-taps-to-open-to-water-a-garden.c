/*
 * @lc app=leetcode id=1326 lang=c
 *
 * [1326] Minimum Number of Taps to Open to Water a Garden
 */

// @lc code=start
// Solution 2: greedy
int minTaps(int n, int *ranges, int rangesSize)
{

    int maxReach[n + 1];
    memset(maxReach, 0, (n + 1) * sizeof(int));

    int start, end;
    for (int i = 0; i < rangesSize; i++)
    {
        start = fmax(0, i - ranges[i]);
        end = fmin(n, i + ranges[i]);
        maxReach[start] = fmax(maxReach[start], end);
    }

    int taps = 0;
    int currEnd = 0;
    int nextEnd = 0;

    for (int i = 0; i <= n; i++)
    {
        if (i > nextEnd)
            return -1;

        if (i > currEnd)
        {
            taps++;
            currEnd = nextEnd;
        }

        nextEnd = fmax(nextEnd, maxReach[i]);
    }

    return taps;
}
// @lc code=end

// Official Solution

// Note: DP / greedy

// Solution 1: DP
// int minTaps(int n, int *ranges, int rangesSize)
// {
//     const int INF = 1e9;
//     int dp[n + 1];
//     for (int i = 0; i < n + 1; i++)
//         dp[i] = INF;

//     dp[0] = 0;
//     int tapStart;
//     int tapEnd;
//     for (int i = 0; i <= n; i++)
//     {
//         tapStart = fmax(0, i - ranges[i]);
//         tapEnd = fmin(n, i + ranges[i]);

//         for (int j = tapStart; j <= tapEnd; j++)
//             dp[tapEnd] = fmin(dp[tapEnd], dp[j] + 1);
//     }

//     if (dp[n] == INF)
//         return -1;

//     return dp[n];
// }