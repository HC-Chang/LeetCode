/*
 * @lc app=leetcode id=976 lang=c
 *
 * [976] Largest Perimeter Triangle
 */

// @lc code=start
int sort(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int largestPerimeter(int *nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), sort);
    for (int i = numsSize - 3; i >= 0; --i)
        if (nums[i] + nums[i + 1] > nums[i + 2])
            return nums[i] + nums[i + 1] + nums[i + 2];

    return 0;
}
// @lc code=end

// Note: math + sorting