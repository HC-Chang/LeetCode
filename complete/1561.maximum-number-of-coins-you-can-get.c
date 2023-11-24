/*
 * @lc app=leetcode id=1561 lang=c
 *
 * [1561] Maximum Number of Coins You Can Get
 */

// @lc code=start
int sort(void *a, void *b) { return *(int *)b - *(int *)a; }
int maxCoins(int *piles, int pilesSize)
{
    qsort(piles, pilesSize, sizeof(int), sort);
    int n = pilesSize / 3;
    for (int i = 1; i < pilesSize / 3; i++)
        piles[1] += piles[i * 2 + 1];

    return piles[1];
}

// @lc code=end
