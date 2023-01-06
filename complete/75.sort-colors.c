/*
 * @lc app=leetcode id=75 lang=c
 *
 * [75] Sort Colors
 */

// @lc code=start
int sort(void *a, void *b)
{
    return *(int *)a - *(int *)b;
}

void sortColors(int *nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), sort);
}
// @lc code=end
