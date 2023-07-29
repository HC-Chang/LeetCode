/*
 * @lc app=leetcode id=808 lang=c
 *
 * [808] Soup Servings
 */

// @lc code=start
double dfs(int a, int b, double **memo)
{
    if (a <= 0 && b <= 0)
        return 0.5;
    if (a <= 0)
        return 1;
    else if (b <= 0)
        return 0;
    if (memo[a][b] > 0)
        return memo[a][b];

    memo[a][b] = 0.25 * (dfs(a - 4, b, memo) + dfs(a - 3, b - 1, memo) + dfs(a - 2, b - 2, memo) + dfs(a - 1, b - 3, memo));
    return memo[a][b];
}

double soupServings(int n)
{
    n = ceil((double)n / 25);
    if (n >= 179)
        return 1;

    double **memo = malloc((n + 1) * sizeof(double *));
    for (int i = 0; i < n + 1; i++)
        memo[i] = calloc(n + 1, sizeof(double));

    double r = dfs(n, n, memo);

    for (int i = 0; i < n + 1; i++)
        free(memo[i]);
    free(memo);

    return r;
}
// @lc code=end
