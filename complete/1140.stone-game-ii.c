/*
 * @lc app=leetcode id=1140 lang=c
 *
 * [1140] Stone Game II
 */

// @lc code=start
int max(int a, int b) { return a > b ? a : b; }
int helper(int *sums, int pilesSize, int i, int m, int **memo)
{
    if (i + 2 * m >= pilesSize)
        return sums[i];
    if (memo[i][m] > 0)
        return memo[i][m];
    int res = 0;
    for (int x = 1; x <= 2 * m; ++x)
    {
        int cur = sums[i] - sums[i + x];
        res = max(res, cur + sums[i + x] - helper(sums, pilesSize, i + x, max(x, m), memo));
    }
    return memo[i][m] = res;
}
int stoneGameII(int *piles, int pilesSize)
{
    int **memo = malloc(pilesSize * sizeof(int *));
    for (int i = 0; i < pilesSize; i++)
        memo[i] = calloc(pilesSize, sizeof(int));
    for (int i = pilesSize - 2; i >= 0; --i)
        piles[i] += piles[i + 1];
    int r = helper(piles, pilesSize, 0, 1, memo);
    for (int i = 0; i < pilesSize; i++)
        free(memo[i]);
    free(memo);
    return r;
}
// @lc code=end
