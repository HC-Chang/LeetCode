/*
 * @lc app=leetcode id=2161 lang=c
 *
 * [2161] Partition Array According to Given Pivot
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *pivotArray(int *nums, int numsSize, int pivot, int *returnSize)
{
    *returnSize = numsSize;
    int *ans = malloc(numsSize * sizeof(int));
    int l = 0;
    int r = 0;
    int cnt = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] < pivot)
            ans[l++] = nums[i];
        else if (nums[i] > pivot)
            nums[r++] = nums[i];
        else
            cnt++;
    }

    for (int i = 0; i < cnt; i++)
        ans[l++] = pivot;
    for (int i = 0; i < r; i++)
        ans[l++] = nums[i];

    return ans;
}
// @lc code=end

// Note: two pointers