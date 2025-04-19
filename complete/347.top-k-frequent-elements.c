/*
 * @lc app=leetcode id=347 lang=c
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct
{
    int index;
    int count;
} DATA;
int sort(const void *a, const void *b) { return (*(DATA *)b).count - (*(DATA *)a).count; }
int *topKFrequent(int *nums, int numsSize, int k, int *returnSize)
{
    *returnSize = k;
    DATA *map = malloc((2 * 1e5 + 1) * sizeof(DATA));
    for (int i = 0; i < 2 * 1e5 + 1; i++)
    {
        map[i].index = -1e5 + i;
        map[i].count = 0;
    }
    for (int i = 0; i < numsSize; i++)
        (map[(nums[i] + 100000)]).count += 1;
    qsort(map, 2 * 1e5 + 1, sizeof(DATA), sort);
    int *r = malloc(k * sizeof(int));
    for (int i = 0; i < k; i++)
        r[i] = map[i].index;

    free(map);
    return r;
}
// @lc code=end
