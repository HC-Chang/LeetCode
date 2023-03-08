/*
 * @lc app=leetcode id=875 lang=c
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
int minEatingSpeed(int *piles, int pilesSize, int h)
{
    int left = 1;
    int right = 1e9;
    int mid;
    int ctr;
    while (left < right)
    {
        mid = left + (right - left) / 2;
        ctr = 0;
        for (int i = 0; i < pilesSize; i++)
            ctr += (piles[i] + mid - 1) / mid;
        if (ctr > h)
            left = mid + 1;
        else
            right = mid;
    }

    return right;
}
// @lc code=end

// Note: binary search