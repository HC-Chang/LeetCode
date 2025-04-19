/*
 * @lc app=leetcode id=217 lang=c
 *
 * [217] Contains Duplicate
 */

// @lc code=start
int sort(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

bool containsDuplicate(int *nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), sort);
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] == nums[i - 1])
            return true;
    }
    return false;
}
// @lc code=end
