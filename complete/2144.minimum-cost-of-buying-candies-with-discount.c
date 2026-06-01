/*
 * @lc app=leetcode id=2144 lang=c
 *
 * [2144] Minimum Cost of Buying Candies With Discount
 */

// @lc code=start
int sort(const void *a, const void *b) { return *(int *)b - *(int *)a; }

int minimumCost(int *cost, int costSize)
{
    qsort(cost, costSize, sizeof(int), sort);
    int i = 0;
    for (int i = 1; i < costSize; i++)
    {
        if (i % 3 == 2)
            continue;
        cost[0] += cost[i];
    }
    return cost[0];
}
// @lc code=end

// Note: sort