/*
 * @lc app=leetcode id=2294 lang=c
 *
 * [2294] Partition Array Such That Maximum Difference Is K
 */

// @lc code=start
int sort(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int partitionArray(int *nums, int numsSize, int k)
{
    qsort(nums, numsSize, sizeof(int), sort);
    int cnt = 1;
    int val = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] - val > k)
        {
            val = nums[i];
            cnt++;
        }
    }
    return cnt;
}
// @lc code=end

// Note: greedy + sorting