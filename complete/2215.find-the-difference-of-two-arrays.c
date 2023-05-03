/*
 * @lc app=leetcode id=2215 lang=c
 *
 * [2215] Find the Difference of Two Arrays
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void push_arr(int val, int *index, int *arr) { arr[(*index)++] = val; }
int **findDifference(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize, int **returnColumnSizes)
{
    int map1[2001] = {0};
    int map2[2001] = {0};
    for (int i = 0; i < nums1Size; i++)
        ++map1[nums1[i] + 1000];
    for (int i = 0; i < nums2Size; i++)
        ++map2[nums2[i] + 1000];
    *returnSize = 2;
    int **arrs = malloc(*returnSize * sizeof(int *));
    arrs[0] = malloc(nums1Size * sizeof(int));
    arrs[1] = malloc(nums2Size * sizeof(int));
    returnColumnSizes[0] = malloc(*returnSize * sizeof(int));
    returnColumnSizes[0][0] = 0;
    returnColumnSizes[0][1] = 0;
    for (int i = 0; i < 2001; i++)
    {
        if (map1[i] == 0 && map2[i] == 0)
            continue;
        if (map1[i] > 0 && map2[i] == 0)
            push_arr(i - 1000, &(returnColumnSizes[0][0]), &(arrs[0][0]));
        else if (map2[i] > 0 && map1[i] == 0)
            push_arr(i - 1000, &(returnColumnSizes[0][1]), &(arrs[1][0]));
    }

    arrs[0] = realloc(arrs[0], returnColumnSizes[0][0] * sizeof(int));
    arrs[1] = realloc(arrs[1], returnColumnSizes[0][1] * sizeof(int));
    return arrs;
}
// @lc code=end
