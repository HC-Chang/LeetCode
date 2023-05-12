/*
 * @lc app=leetcode id=2140 lang=c
 *
 * [2140] Solving Questions With Brainpower
 */

// @lc code=start
long long max(long long a, long long b) { return a > b ? a : b; }
long long mostPoints(int **questions, int questionsSize, int *questionsColSize)
{
    long long *dp = malloc(questionsSize * sizeof(long long));
    dp[questionsSize - 1] = questions[questionsSize - 1][0];
    for (int i = questionsSize - 2; i >= 0; --i)
        dp[i] = max(dp[i + 1], ((i + questions[i][1] + 1 < questionsSize) ? dp[i + questions[i][1] + 1] : 0) + questions[i][0]);
    long long r = dp[0];
    free(dp);
    return r;
}
// @lc code=end
