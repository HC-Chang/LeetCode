/*
 * @lc app=leetcode id=1431 lang=c
 *
 * [1431] Kids With the Greatest Number of Candies
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool *kidsWithCandies(int *candies, int candiesSize, int extraCandies, int *returnSize)
{
    int max = candies[0];
    for (int i = 1; i < candiesSize; i++)
    {
        if (candies[i] > max)
            max = candies[i];
    }
    *returnSize = candiesSize;
    bool *r = malloc((*returnSize) * sizeof(bool));
    for (int i = 0; i < candiesSize; i++)
    {
        if (candies[i] + extraCandies >= max)
            r[i] = true;
        else
            r[i] = false;
    }
    return r;
}
// @lc code=end
