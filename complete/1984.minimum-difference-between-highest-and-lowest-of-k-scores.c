/*
 * @lc app=leetcode id=1984 lang=c
 *
 * [1984] Minimum Difference Between Highest and Lowest of K Scores
 */

// @lc code=start
int sort(void *a, void *b) { return *(int *)a - *(int *)b; }
int min(int a, int b) { return a < b ? a : b; }
int minimumDifference(int *nums, int numsSize, int k)
{
    if (numsSize < k)
        return 0;
    qsort(nums, numsSize, sizeof(int), sort);
    int r = INT_MAX;
    for (int i = 0; i <= numsSize - k; i++)
        r = min(nums[i + k - 1] - nums[i], r);
    return r;
}

// @lc code=end
