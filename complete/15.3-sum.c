/*
 * @lc app=leetcode id=15 lang=c
 *
 * [15] 3Sum
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int sort(void *a, void *b) { return *(int *)a - *(int *)b; }
void push(int i, int j, int k, int *nums, int *returnSize, int ***r)
{
    r[0][*returnSize] = malloc(3 * sizeof(int));
    r[0][*returnSize][0] = nums[i];
    r[0][*returnSize][1] = nums[j];
    r[0][*returnSize][2] = nums[k];
    ++*returnSize;
}

int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    qsort(nums, numsSize, sizeof(int), sort);

    *returnSize = 0;
    int **r = malloc(30000 * sizeof(int *));
    int i, j, k;
    int x, sum;
    for (i = 0; i < numsSize - 2; i++)
    {
        x = nums[i];
        if (i > 0 && x == nums[i - 1])
            continue;
        if (x + nums[i + 1] + nums[i + 2] > 0)
            break;
        if (x + nums[numsSize - 1] + nums[numsSize - 2] < 0)
            continue;
        j = i + 1;
        k = numsSize - 1;
        while (j < k)
        {
            sum = x + nums[j] + nums[k];
            if (sum > 0)
                k--;
            else if (sum < 0)
                j++;
            else
            {
                push(i, j, k, nums, returnSize, &r);
                j++;
                while (j < k && nums[j] == nums[j - 1])
                    j++;
                k--;
                while (j < k && nums[k] == nums[k + 1])
                    k--;
            }
        }
    }

    returnColumnSizes[0] = malloc(*returnSize * sizeof(int));
    for (int i = 0; i < *returnSize; i++)
        returnColumnSizes[0][i] = 3;

    return r;
}
// @lc code=end
