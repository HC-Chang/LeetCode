/*
 * @lc app=leetcode id=2191 lang=c
 *
 * [2191] Sort the Jumbled Numbers
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int convert(int val, int *mapping)
{
    if (val == 0)
        return mapping[0];
    int ans = 0;
    int offset = 1;
    while (val)
    {
        ans += mapping[val % 10] * offset;
        offset *= 10;
        val /= 10;
    }
    return ans;
}

typedef struct
{
    int idx;
    int val;
} DATA;

int sort(const void *a, const void *b) { return ((DATA *)a)->val - ((DATA *)b)->val; }

int *sortJumbled(int *mapping, int mappingSize, int *nums, int numsSize,
                 int *returnSize)
{

    int n = numsSize;
    DATA d[n];
    for (int i = 0; i < n; i++)
    {
        d[i].idx = i;
        d[i].val = convert(nums[i], mapping);
    }

    qsort(&d, n, sizeof(DATA), sort);

    *returnSize = n;
    int *ans = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        ans[i] = nums[d[i].idx];
    return ans;
}
// @lc code=end

// Note: sorting