/*
 * @lc app=leetcode id=1887 lang=c
 *
 * [1887] Reduction Operations to Make the Array Elements Equal
 */

// @lc code=start
int reductionOperations(int *nums, int numsSize)
{
    int counts[50001] = {0};
    for (int i = 0; i < numsSize; i++)
        ++counts[nums[i]];

    int count = 0;
    int r = 0;
    for (int i = 50000; i >= 1; i--)
    {
        if (counts[i] > 0)
        {
            count += counts[i];
            r += count - counts[i];
        }
    }
    return r;
}
// @lc code=end
