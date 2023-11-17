/*
 * @lc app=leetcode id=1877 lang=c
 *
 * [1877] Minimize Maximum Pair Sum in Array
 */

// @lc code=start
int sort(void *a, void *b) { return *(int *)a - *(int *)b; }
int minPairSum(int *nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), sort);
    nums[0] += nums[numsSize - 1];
    for (int i = 1; i < numsSize / 2; i++)
    {
        nums[i] += nums[numsSize - 1 - i];
        if (nums[i] > nums[0])
            nums[0] = nums[i];
    }

    return nums[0];
}
// @lc code=end
