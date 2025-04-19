/*
 * @lc app=leetcode id=2009 lang=c
 *
 * [2009] Minimum Number of Operations to Make Array Continuous
 */

// @lc code=start
int sort(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int minOperations(int *nums, int numsSize)
{
    if (numsSize == 1)
        return 0;
    qsort(nums, numsSize, sizeof(int), sort);
    int idx = 1;
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] != nums[idx - 1])
            nums[idx++] = nums[i];
    }
    int cnt = INT_MAX;
    for (int i = 0, j = 0, m = idx; i < m; ++i)
    {
        while (j < m && nums[j] < nums[i] + numsSize)
            ++j;
        cnt = fmin(cnt, numsSize - (j - i));
    }
    return cnt;
}
// @lc code=end
