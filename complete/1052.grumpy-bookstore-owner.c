/*
 * @lc app=leetcode id=1052 lang=c
 *
 * [1052] Grumpy Bookstore Owner
 */

// @lc code=start
int maxSatisfied(int *customers, int customersSize, int *grumpy, int grumpySize, int minutes)
{
    int res = 0;
    int max = 0;
    int sums[customersSize + 1];
    memset(sums, 0, sizeof(sums));

    for (int i = 0; i < customersSize; ++i)
    {
        sums[i + 1] = sums[i];
        if (grumpy[i] == 0)
            res += customers[i];
        else
            sums[i + 1] += customers[i];
        if (i + 1 - minutes >= 0)
            max = fmax(max, sums[i + 1] - sums[i + 1 - minutes]);
    }
    return res + max;
}
// @lc code=end
