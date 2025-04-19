/*
 * @lc app=leetcode id=786 lang=c
 *
 * [786] K-th Smallest Prime Fraction
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct
{
    int v1;
    int v2;
} DATA;
int sort(const void *a, const void *b) { return ((DATA *)a)->v1 * ((DATA *)b)->v2 - ((DATA *)b)->v1 * ((DATA *)a)->v2; }
int *kthSmallestPrimeFraction(int *arr, int arrSize, int k, int *returnSize)
{
    DATA *d = calloc(arrSize * (arrSize - 1) / 2, sizeof(DATA));
    int idx = 0;
    for (int i = 0; i < arrSize; i++)
    {
        for (int j = i + 1; j < arrSize; j++)
        {
            d[idx].v1 = arr[i];
            d[idx++].v2 = arr[j];
        }
    }
    qsort(d, idx, sizeof(DATA), sort);

    *returnSize = 2;
    arr[0] = d[k - 1].v1;
    arr[1] = d[k - 1].v2;
    free(d);
    return arr;
}
// @lc code=end

// Note: sorting / heap