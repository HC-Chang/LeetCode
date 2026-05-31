/*
 * @lc app=leetcode id=128 lang=c
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
int sort(const void *a, const void *b) { return *(int *)a > *(int *)b; }

int longestConsecutive(int *nums, int numsSize)
{
    if (numsSize < 2)
        return numsSize;
    qsort(nums, numsSize, sizeof(int), sort);

    int max_count = 1;
    int count = 1;
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] == nums[i - 1])
            continue;
        if (nums[i] - nums[i - 1] == 1)
            count++;
        else
        {
            if (count > max_count)
                max_count = count;

            count = 1;
        }
    }
    return fmax(max_count, count);
}
// @lc code=end

// Hash Table or Union Find