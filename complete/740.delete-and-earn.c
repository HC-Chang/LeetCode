/*
 * @lc app=leetcode id=740 lang=c
 *
 * [740] Delete and Earn
 */

// @lc code=start
int deleteAndEarn(int *nums, int numsSize)
{
    int *sums = calloc(10001, sizeof(int));
    for (int i = 0; i < numsSize; i++)
        sums[nums[i]] += nums[i];
    for (int i = 2; i <= 10000; i++)
        sums[i] = fmax(sums[i - 1], sums[i - 2] + sums[i]);

    int r = sums[10000];
    free(sums);
    return r;
}
// @lc code=end

// Note: DP