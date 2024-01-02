/*
 * @lc app=leetcode id=2610 lang=c
 *
 * [2610] Convert an Array Into a 2D Array With Conditions
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **findMatrix(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    int hash[201] = {0};
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (++hash[nums[i]] > *returnSize)
            *returnSize = hash[nums[i]];
    }

    returnColumnSizes[0] = calloc(*returnSize, sizeof(int));
    int **ans = malloc(*returnSize * sizeof(int *));
    for (int i = 0; i < *returnSize; i++)
        ans[i] = calloc(200, sizeof(int));
    for (int i = 1; i < 201; i++)
    {
        if (hash[i] > 0)
        {
            for (int j = 0; j < hash[i]; j++)
                ans[j][returnColumnSizes[0][j]++] = i;
        }
    }

    return ans;
}
// @lc code=end

// Note: hash table