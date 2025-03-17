/*
 * @lc app=leetcode id=2206 lang=c
 *
 * [2206] Divide Array Into Equal Pairs
 */

// @lc code=start
int sort(const void *a, const void *b) { return *(int *)a - *(int *)b; }
bool divideArray(int *nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), sort);
    for (int i = 0; i < numsSize; i += 2)
    {
        if (nums[i] != nums[i + 1])
            return false;
    }
    return true;
}
// @lc code=end

// Note: hash table / bit manipulation + counting
