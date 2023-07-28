/*
 * @lc app=leetcode id=486 lang=c
 *
 * [486] Predict the Winner
 */

// @lc code=start
bool PredictTheWinner(int *nums, int numsSize)
{
    int **dp = malloc(numsSize * sizeof(int *));
    for (int i = 0; i < numsSize; i++)
    {
        dp[i] = calloc(numsSize, sizeof(int));
        dp[i][i] = nums[i];
    }

    for (int i = numsSize - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < numsSize; j++)
            dp[i][j] = fmax(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
    }

    bool b = dp[0][numsSize - 1] >= 0;
    for (int i = 0; i < numsSize; i++)
        free(dp[i]);
    free(dp);
    return b;
}
// @lc code=end
