/*
 * @lc app=leetcode id=2256 lang=c
 *
 * [2256] Minimum Average Difference
 */

// @lc code=start
int minimumAverageDifference(int *nums, int numsSize)
{
    if (numsSize <= 1)
        return 0;

    long sums, sums_total = 0;
    for (int i = 0; i < numsSize; i++)
        sums_total += nums[i];

    long difs;
    long min = 65535;
    int min_index = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (i == 0)
            sums = nums[i];
        else
            sums += nums[i];
        difs = sums / (i + 1);
        if (numsSize - i - 1 > 0)
            difs -= (sums_total - sums) / (numsSize - i - 1);
        if (difs < 0)
            difs = -difs;
        if (difs < min)
        {
            min = difs;
            min_index = i;
        }
    }

    return min_index;
}
// @lc code=end
