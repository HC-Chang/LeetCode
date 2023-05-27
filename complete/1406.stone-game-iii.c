/*
 * @lc app=leetcode id=1406 lang=c
 *
 * [1406] Stone Game III
 */

// @lc code=start
int max(int a, int b) { return a > b ? a : b; }
char *stoneGameIII(int *stoneValue, int stoneValueSize)
{
    int dp_size = 4;
    int *dp = calloc(dp_size, sizeof(int));
    for (int i = stoneValueSize - 1; i >= 0; --i)
    {
        dp[i % 4] = -1e9;
        for (int k = 0, take = 0; k < 3 && i + k < stoneValueSize; ++k)
            dp[i % 4] = max(dp[i % 4], (take += stoneValue[i + k]) - dp[(i + k + 1) % 4]);
    }
    int r = dp[0];
    free(dp);
    return r == 0 ? "Tie" : (r > 0 ? "Alice" : "Bob");
}
// @lc code=end
