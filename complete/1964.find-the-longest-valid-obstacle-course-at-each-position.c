/*
 * @lc app=leetcode id=1964 lang=c
 *
 * [1964] Find the Longest Valid Obstacle Course at Each Position
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *longestObstacleCourseAtEachPosition(int *obstacles, int obstaclesSize, int *returnSize)
{
    *returnSize = obstaclesSize;
    int *dp = malloc((obstaclesSize + 1) * sizeof(int));
    for (int i = 0; i < obstaclesSize + 1; i++)
        dp[i] = INT_MAX;
    dp[0] = 0;
    int *r = calloc(obstaclesSize, sizeof(int));
    int x;
    int left, right, mid;
    int ans;
    for (int i = 0; i < obstaclesSize; i++)
    {
        x = obstacles[i];
        left = 0;
        right = obstaclesSize - 1;
        ans = 0;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (dp[mid] <= x)
            {
                ans = mid;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        r[i] = ans + 1;
        dp[ans + 1] = dp[ans + 1] < x ? dp[ans + 1] : x;
    }
    return r;
}
// @lc code=end
