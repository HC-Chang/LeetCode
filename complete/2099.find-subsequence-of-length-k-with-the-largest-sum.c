/*
 * @lc app=leetcode id=2099 lang=c
 *
 * [2099] Find Subsequence of Length K With the Largest Sum
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct
{
    int idx;
    int val;
} DATA;

int sort1(const void *a, const void *b)
{
    return ((DATA *)b)->val - ((DATA *)a)->val;
}

int sort2(const void *a, const void *b)
{
    return ((DATA *)a)->idx - ((DATA *)b)->idx;
}
int *maxSubsequence(int *nums, int numsSize, int k, int *returnSize)
{
    *returnSize = k;
    DATA arr[numsSize];
    for (int i = 0; i < numsSize; i++)
        arr[i] = (DATA){i, nums[i]};

    qsort(arr, numsSize, sizeof(DATA), sort1);

    qsort(arr, k, sizeof(DATA), sort2);

    int *ans = malloc(k * sizeof(int));
    for (int i = 0; i < k; i++)
        ans[i] = nums[arr[i].idx];
    return ans;
}
// @lc code=end

// Note: heap + sorting