/*
 * @lc app=leetcode id=2090 lang=c
 *
 * [2090] K Radius Subarray Averages
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *getAverages(int *nums, int numsSize, int k, int *returnSize)
{
    *returnSize = numsSize;
    int *r = malloc(*returnSize * sizeof(int));
    int count = 0;
    int t_count = k * 2 + 1;
    unsigned long long sum = 0;
    for (int i = 0; i < numsSize; i++)
    {
        sum += nums[i];
        count++;
        if (i < k || i > numsSize - 1 - k)
            r[i] = -1;
        else if (k == 0)
            r[i] = nums[i];

        if (count == t_count)
        {
            r[i - k] = sum / t_count;
            sum -= nums[i - t_count + 1];
            count--;
        }
    }

    return r;
}
// @lc code=end
