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
    long *sums = calloc(numsSize, sizeof(long));
    sums[0] = nums[0];
    for (int i = 1; i < numsSize; i++)
        sums[i] = sums[i - 1] + nums[i];
    long *sums_dif = calloc(numsSize, sizeof(long));
    for (int i = 0; i < numsSize - 1; i++)
        sums_dif[i] = sums[numsSize - 1] - sums[i];
    long difs;
    long min = 65535;
    int min_index = 0;
    for (int i = 0; i < numsSize; i++)
    {
        difs = sums[i] / (i + 1);
        if (numsSize - i - 1 > 0)
            difs -= sums_dif[i] / (numsSize - i - 1);
        if (difs < 0)
            difs = -difs;
        if (difs < min)
        {
            min = difs;
            min_index = i;
        }
    }

    free(sums);
    free(sums_dif);
    return min_index;
}
// @lc code=end
