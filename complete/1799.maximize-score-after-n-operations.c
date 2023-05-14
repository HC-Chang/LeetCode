/*
 * @lc app=leetcode id=1799 lang=c
 *
 * [1799] Maximize Score After N Operations
 */

// @lc code=start
int gcd(int a, int b)
{
    if (a % b)
        return gcd(b, a % b);
    else
        return b;
}

int max(int a, int b) { return a > b ? a : b; }

int maxScore(int *nums, int numsSize)
{
    int **gcds = malloc(numsSize * sizeof(int *));
    for (int i = 0; i < numsSize; i++)
        gcds[i] = calloc(numsSize, sizeof(int));
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (gcds[i][j] == 0)
                gcds[i][j] = gcd(nums[i], nums[j]);
        }
    }

    int *dp = malloc((1 << numsSize) * sizeof(int));
    dp[0] = 0;
    for (int i = 1; i < 1 << numsSize; i++)
        dp[i] = INT_MIN;

    int r;
    for (int s = 0; s < (1 << numsSize); s++)
    {
        if (dp[s] == INT_MIN)
            continue;
        r = 0;
        for (int i = 0; i < numsSize; i++)
            if (s & (1 << i))
                r++;

        for (int i = 0; i < numsSize; i++)
        {
            if (s & (1 << i))
                continue;

            for (int j = i + 1; j < numsSize; j++)
            {
                if (s & (1 << j))
                    continue;

                dp[s | (1 << i) | (1 << j)] = max(
                    dp[s | (1 << i) | (1 << j)],
                    dp[s] + (r / 2 + 1) * gcds[i][j]);
            }
        }
    }

    int max_score = dp[(1 << numsSize) - 1];
    for (int i = 0; i < numsSize; i++)
        free(gcds[i]);
    free(gcds);
    free(dp);
    return max_score;
}

// @lc code=end
