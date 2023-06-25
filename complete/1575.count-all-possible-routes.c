/*
 * @lc app=leetcode id=1575 lang=c
 *
 * [1575] Count All Possible Routes
 */

// @lc code=start
int countRoutes(int *locations, int locationsSize, int start, int finish, int fuel)
{
    int **dp = malloc(locationsSize * sizeof(int *));
    for (int i = 0; i < locationsSize; i++)
        dp[i] = calloc(fuel + 1, sizeof(int));
    for (int i = 0; i <= fuel; i++)
        dp[finish][i] = 1;

    for (int j = 1; j <= fuel; j++)
    {
        for (int i = 0; i < locationsSize; i++)
        {
            for (int k = 0; k < locationsSize; k++)
            {
                if (k == i)
                    continue;

                if (abs(locations[i] - locations[k]) <= j)
                    dp[i][j] = (dp[i][j] + dp[k][j - abs(locations[i] - locations[k])]) % 1000000007;
            }
        }
    }
    int count = dp[start][fuel];
    for (int i = 0; i < locationsSize; i++)
        free(dp[i]);
    free(dp);
    return count;
}
// @lc code=end

// Official Solution