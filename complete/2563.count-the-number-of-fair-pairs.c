/*
 * @lc app=leetcode id=2563 lang=c
 *
 * [2563] Count the Number of Fair Pairs
 */

// @lc code=start
long long lower_bound(int val, int *nums, int numsSize)
{
    int left = 0, right = numsSize - 1;
    long long result = 0;
    while (left < right)
    {
        int sum = nums[left] + nums[right];
        if (sum < val)
        {
            result += (right - left);
            left++;
        }
        else
            right--;
    }
    return result;
}

int sort(void *a, void *b) { return *(int *)a - *(int *)b; }

long long countFairPairs(int *nums, int numsSize, int lower, int upper)
{
    qsort(nums, numsSize, sizeof(int), sort);
    return lower_bound(upper + 1, nums, numsSize) - lower_bound(lower, nums, numsSize);
}
// @lc code=end

// Note: two pointers + binary search + sorting

// Official Solution