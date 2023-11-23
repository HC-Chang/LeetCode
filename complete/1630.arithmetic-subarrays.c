/*
 * @lc app=leetcode id=1630 lang=c
 *
 * [1630] Arithmetic Subarrays
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int sort(void *a, void *b) { return *(int *)a - *(int *)b; }
bool *checkArithmeticSubarrays(int *nums, int numsSize, int *l, int lSize, int *r, int rSize, int *returnSize)
{
    int copy[numsSize];
    *returnSize = lSize;
    bool *r_arr = malloc((*returnSize) * sizeof(bool));
    int len;
    int diff;
    for (int i = 0; i < lSize; i++)
    {
        len = r[i] - l[i] + 1;
        memcpy(copy, nums + l[i], len * sizeof(int));
        qsort(copy, len, sizeof(int), sort);
        diff = copy[1] - copy[0];
        r_arr[i] = true;
        for (int j = 2; j < len; j++)
        {
            if (diff != copy[j] - copy[j - 1])
            {
                r_arr[i] = false;
                break;
            }
        }
    }

    return r_arr;
}
// @lc code=end
