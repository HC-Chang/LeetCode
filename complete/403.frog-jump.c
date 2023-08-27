/*
 * @lc app=leetcode id=403 lang=c
 *
 * [403] Frog Jump
 */

// @lc code=start
bool canCross(int *stones, int stonesSize)
{
    bool dp[stonesSize][stonesSize];
    memset(dp, 0, stonesSize * stonesSize * sizeof(bool));
    dp[0][0] = true;
    int tmp;
    for (int i = 1, l = 0; i < stonesSize - 1; i++)
    {
        while (stones[i] - stones[l] > i)
            l++;
        for (int j = l; j < i; j++)
        {
            tmp = stones[i] - stones[j];
            if (dp[j][tmp - 1] || dp[j][tmp] || dp[j][tmp + 1])
                dp[i][tmp] = true;
        }
    }

    for (int i = stonesSize - 2; i >= 0; i--)
    {
        tmp = stones[stonesSize - 1] - stones[i];
        if (tmp > stonesSize - 1)
            break;
        if (dp[i][tmp - 1] || dp[i][tmp] || (tmp + 1 <= stonesSize - 1 && dp[i][tmp + 1]))
            return true;
    }

    return false;
}
// @lc code=end

// Note: DP