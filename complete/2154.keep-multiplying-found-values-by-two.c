/*
 * @lc app=leetcode id=2154 lang=c
 *
 * [2154] Keep Multiplying Found Values by Two
 */

// @lc code=start
int sort(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int findFinalValue(int *nums, int numsSize, int original)
{
    int idx = 0;
    for (int i = 0; i < numsSize; i++)
        if (nums[i] % original == 0)
            nums[idx++] = nums[i];
    if (idx == 0)
        return original;

    qsort(nums, idx, sizeof(int), sort);
    int i = 0;
    while (i < idx && nums[i] <= original)
    {
        if (nums[i++] == original)
            original *= 2;
    }

    return original;
}
// @lc code=end

// Note: array + hash table + sorting + simulation
