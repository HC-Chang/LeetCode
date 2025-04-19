/*
 * @lc app=leetcode id=1833 lang=c
 *
 * [1833] Maximum Ice Cream Bars
 */

// @lc code=start
int sort(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int maxIceCream(int *costs, int costsSize, int coins)
{
    qsort(costs, costsSize, sizeof(int), sort);
    int i;
    for (i = 0; i < costsSize; i++)
    {
        if (coins >= costs[i])
            coins -= costs[i];
        else
            return i;
    }
    return i;
}
// @lc code=end
