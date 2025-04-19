/*
 * @lc app=leetcode id=1331 lang=c
 *
 * [1331] Rank Transform of an Array
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct
{
    int val;
    int idx;
} DATA;

int sort(const void *a, const void *b) { return ((DATA *)a)->val - ((DATA *)b)->val; }

int *arrayRankTransform(int *arr, int arrSize, int *returnSize)
{
    *returnSize = arrSize;
    if (*returnSize == 0)
        return NULL;

    DATA *d = malloc(arrSize * sizeof(DATA));
    for (int i = 0; i < arrSize; i++)
    {
        d[i].val = arr[i];
        d[i].idx = i;
    }

    qsort(d, arrSize, sizeof(DATA), sort);
    int rank = 1;
    arr[d[0].idx] = rank;
    for (int i = 1; i < arrSize; i++)
    {
        if (d[i].val != d[i - 1].val)
            rank++;
        arr[d[i].idx] = rank;
    }
    free(d);

    return arr;
}
// @lc code=end

// Note: hash table + sorting