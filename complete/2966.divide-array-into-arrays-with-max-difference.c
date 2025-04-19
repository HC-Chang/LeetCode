/*
 * @lc app=leetcode id=2966 lang=c
 *
 * [2966] Divide Array Into Arrays With Max Difference
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int sort(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int **divideArray(int *nums, int numsSize, int k, int *returnSize, int **returnColumnSizes)
{

    qsort(nums, numsSize, sizeof(int), sort);
    int diff;
    *returnSize = numsSize / 3;
    returnColumnSizes[0] = malloc((*returnSize) * sizeof(int));

    int **r = malloc((*returnSize) * sizeof(int *));
    for (int i = 0; i < (numsSize / 3); i++)
    {
        returnColumnSizes[0][i] = 3;
        r[i] = malloc(3 * sizeof(int));
    }

    int grp = 0;
    int idx = 0;
    r[grp][idx++] = nums[0];

    for (int i = 1; i < numsSize; i++)
    {
        diff = nums[i] - r[grp][0];
        if (diff > k && idx != 0)
        {
            *returnSize = 0;
            return NULL;
        }
        else
        {
            r[grp][idx++] = nums[i];
            if (idx == 3)
            {
                idx = 0;
                grp++;
            }
        }
    }

    return r;
}
// @lc code=end

// Note: sorting