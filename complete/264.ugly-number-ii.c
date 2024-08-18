/*
 * @lc app=leetcode id=264 lang=c
 *
 * [264] Ugly Number II
 */

// @lc code=start
int nthUglyNumber(int n)
{
    int ugly[n];
    ugly[0] = 1;

    int idx_2 = 0, idx_3 = 0, idx_5 = 0;
    int next_2 = 2, next_3 = 3, next_5 = 5;
    int nextUglyNumber;
    for (int i = 1; i < n; i++)
    {
        nextUglyNumber = fmin(next_2, fmin(next_3, next_5));
        ugly[i] = nextUglyNumber;

        if (nextUglyNumber == next_2)
            next_2 = ugly[++idx_2] * 2;

        if (nextUglyNumber == next_3)
            next_3 = ugly[++idx_3] * 3;

        if (nextUglyNumber == next_5)
            next_5 = ugly[++idx_5] * 5;
    }

    return ugly[n - 1];
}
// @lc code=end

// Note: DP

// Official Solution