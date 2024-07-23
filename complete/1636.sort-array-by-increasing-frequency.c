/*
 * @lc app=leetcode id=1636 lang=c
 *
 * [1636] Sort Array by Increasing Frequency
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct
{
    int idx;
    int cnt;
} DATA;

int sort(void *a, void *b)
{
    if (((DATA *)a)->cnt == ((DATA *)b)->cnt)
        return ((DATA *)b)->idx - ((DATA *)a)->idx;
    return ((DATA *)a)->cnt - ((DATA *)b)->cnt;
}

int *frequencySort(int *nums, int numsSize, int *returnSize)
{
    DATA d[201];
    for (int i = 0; i < 201; i++)
    {
        d[i].idx = -100 + i;
        d[i].cnt = 0;
    }
    for (int i = 0; i < numsSize; i++)
        ++d[nums[i] + 100].cnt;

    qsort(d, 201, sizeof(DATA), sort);

    *returnSize = numsSize;
    int idx = 0;
    for (int i = 0; i < 201; i++)
    {
        for (int j = 0; j < d[i].cnt; j++)
            nums[idx++] = d[i].idx;
        if (idx == numsSize)
            break;
    }
    return nums;
}
// @lc code=end

// Note: hash table + sorting