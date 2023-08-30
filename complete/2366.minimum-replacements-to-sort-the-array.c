/*
 * @lc app=leetcode id=2366 lang=c
 *
 * [2366] Minimum Replacements to Sort the Array
 */

// @lc code=start
long long minimumReplacement(int *nums, int numsSize)
{
    long long count = 0;

    int arr = nums[numsSize - 1];
    int n;
    for (int i = numsSize - 1; i >= 0; i--)
    {
        n = (nums[i] - 1) / arr;
        count += n;
        arr = nums[i] / (n + 1);
    }

    return count;
}
// @lc code=end

// Note: greedy
