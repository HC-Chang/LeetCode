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
    int sum = 0;
    int i = 0;
    while (i < costSize)
    {
        if (i == costSize - 1)
            sum += cost[i];
        else
            sum += cost[i] + cost[i + 1];
        i += 3;
    }
    return sum;
}

// @lc code=end
