/*
 * @lc app=leetcode id=977 lang=c
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// Solution 2: two pointer
int *sortedSquares(int *nums, int numsSize, int *returnSize)
{
    *returnSize = numsSize;
    int l = 0;
    int r = numsSize - 1;
    int ll, rr;
    int *ans = malloc(numsSize * sizeof(int));
    for (int i = numsSize - 1; i >= 0; i--)
    {
        ll = nums[l] * nums[l];
        rr = nums[r] * nums[r];
        if (ll > rr)
        {
            ans[i] = ll;
            l++;
        }
        else
        {
            ans[i] = rr;
            r--;
        }
    }
    return ans;
}
// @lc code=end

// Note: sorting + two pointer

// Sloution 1: qsort
int sort(void *a, void *b) { return *(int *)a - *(int *)b; }
int *sortedSquares(int *nums, int numsSize, int *returnSize)
{
    *returnSize = numsSize;
    for (int i = 0; i < numsSize; i++)
        nums[i] *= nums[i];
    qsort(nums, numsSize, sizeof(int), sort);
    return nums;
}