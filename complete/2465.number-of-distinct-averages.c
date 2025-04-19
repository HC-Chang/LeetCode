/*
 * @lc app=leetcode id=2465 lang=c
 *
 * [2465] Number of Distinct Averages
 */

// @lc code=start
int sort(const void *a, const void *b) { return *(int *)a > *(int *)b; }
int distinctAverages(int *nums, int numsSize)
{
    if (numsSize == 2)
        return 1;
    qsort(nums, numsSize, sizeof(int), sort);
    unsigned int len = nums[numsSize - 1] + nums[numsSize - 2] + 1;
    char sums[len];
    memset(sums, 0, sizeof(sums));

    for (int i = 0; i < (numsSize / 2); i++)
    {
        if (sums[nums[i] + nums[numsSize - i - 1]] == 0)
            ++sums[nums[i] + nums[numsSize - i - 1]];
    }

    int count = 0;
    for (int i = 0; i < len; i++)
    {
        if (sums[i] > 0)
            count++;
    }
    return count;
}
// @lc code=end

// Note: sorting + hash table