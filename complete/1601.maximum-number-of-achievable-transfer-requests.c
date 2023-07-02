/*
 * @lc app=leetcode id=1601 lang=c
 *
 * [1601] Maximum Number of Achievable Transfer Requests
 */

// @lc code=start
int maximumRequests(int n, int **requests, int requestsSize, int *requestsColSize)
{
    int *delta = malloc(sizeof(int) * n);
    int ans = 0, m = requestsSize;

    for (int mask = 0; mask < (1 << m); ++mask)
    {
        int cnt = __builtin_popcount(mask);
        if (cnt <= ans)
            continue;

        memset(delta, 0, sizeof(int) * n);
        for (int i = 0; i < m; ++i)
        {
            if (mask & (1 << i))
            {
                ++delta[requests[i][0]];
                --delta[requests[i][1]];
            }
        }
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            if (delta[i] != 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
            ans = cnt;
    }
    return ans;
}
// @lc code=end

// Official Solution