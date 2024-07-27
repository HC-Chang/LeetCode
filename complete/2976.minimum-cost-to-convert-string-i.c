/*
 * @lc app=leetcode id=2976 lang=c
 *
 * [2976] Minimum Cost to Convert String I
 */

// @lc code=start
#define THRESHOLD 1e7
long long minimumCost(char *source, char *target, char *original,
                      int originalSize, char *changed, int changedSize,
                      int *cost, int costSize)
{

    int n = originalSize;
    int costs[26][26];

    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
            costs[i][j] = THRESHOLD;
        costs[i][i] = 0;
    }

    int x, y;
    for (int i = 0; i < n; i++)
    {
        x = original[i] - 'a';
        y = changed[i] - 'a';
        costs[x][y] = fmin(cost[i], costs[x][y]);
    }

    for (int k = 0; k < 26; ++k)
    {
        for (int i = 0; i < 26; ++i)
        {
            for (int j = 0; j < 26; ++j)
            {
                costs[i][j] = fmin(costs[i][j], costs[i][k] + costs[k][j]);
            }
        }
    }

    long long sum = 0;
    int nn = strlen(source);
    for (int i = 0; i < nn; i++)
    {
        if (source[i] == target[i])
            continue;
        x = source[i] - 'a';
        y = target[i] - 'a';
        if (costs[x][y] >= THRESHOLD)
            return -1;
        else
            sum += costs[x][y];
    }
    return sum;
}
// @lc code=end

// Note: graph